/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-19 11:58:26 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-19 11:58:26 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	pipe_and_fork(int *pipefd, t_pipex *pipex)
{
	pid_t	pid;

	if (pipe(pipefd) == -1)
		bash_error_exit("pipe", pipex);
	pid = fork();
	if (pid == -1)
		bash_error_exit("fork", pipex);
	return (pid);
}

void	close_pipe(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
}
