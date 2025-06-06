/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 17:07:04 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-18 17:07:04 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_execution(t_pipex *pipex, int i)
{
	int		pipefd[2];
	pid_t	pid;
	int		infile_fd;

	pid = pipe_and_fork(pipefd, pipex);
	if (pid == 0)
	{
		infile_fd = open(pipex->infile, O_RDONLY);
		dup2(infile_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_pipe(pipefd[0], pipefd[1]);
		close(infile_fd);
		if (pipex->cmds[i].no_cmd)
			cmd_not_found(pipex->cmds[i].args[0], pipex);
		if (!pipex->error_flag)
			execve(pipex->cmds[i].path, pipex->cmds[i].args, pipex->envp);
	}
	else
	{
		pipex->prev_pipefd[0] = pipefd[0];
		pipex->prev_pipefd[1] = pipefd[1];
		close(pipefd[1]);
	}
}

void	general_execution(t_pipex *pipex, int i)
{
	int		pipefd[2];
	pid_t	pid;

	pid = pipe_and_fork(pipefd, pipex);
	if (pid == 0)
	{
		dup2(pipex->prev_pipefd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_pipe(pipefd[0], pipefd[1]);
		close(pipex->prev_pipefd[0]);
		if (pipex->cmds[i].no_cmd)
			cmd_not_found(pipex->cmds[i].args[0], pipex);
		if (!pipex->error_flag)
			execve(pipex->cmds[i].path, pipex->cmds[i].args, pipex->envp);
	}
	else
	{
		close(pipex->prev_pipefd[0]);
		close(pipefd[1]);
		pipex->prev_pipefd[0] = pipefd[0];
		pipex->prev_pipefd[1] = pipefd[1];
	}
}

void	final_execution(t_pipex *pipex, int i)
{
	pid_t	pid;
	int		outfile_fd;

	pid = fork();
	if (pid == -1)
		bash_error_exit("fork", pipex);
	if (pid == 0)
	{
		outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(pipex->prev_pipefd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		if (pipex->cmds[i].no_cmd)
			cmd_not_found(pipex->cmds[i].args[0], pipex);
		if (!pipex->error_flag)
			execve(pipex->cmds[i].path, pipex->cmds[i].args, pipex->envp);
	}
	else
	{
		close(pipex->prev_pipefd[0]);
	}
}

void	wait_children(t_pipex *pipex)
{
	int		status;
	pid_t	pid;
	int		i;

	i = 0;
	while (i < pipex->cmd_num)
	{
		pid = wait(&status);
		if (pid == -1)
			break ;
		i++;
	}
}
