/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 17:55:50 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-20 17:55:50 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_files(t_pipex *pipex)
{
	int	fd;

	fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		bash_error_continue(pipex->outfile);
		pipex->error_flag = OUT_FILE_ERROR;
		close(fd);
	}
	close(fd);
	fd = open(pipex->infile, O_RDONLY);
	if (fd == -1)
	{
		bash_error_exit(pipex->infile, pipex);
		close(fd);
	}
	close(fd);
}

void	bash_error_exit(char *error_type, t_pipex *pipex)
{
	write(STDERR_FILENO, "bash: ", 6);
	perror(error_type);
	cleanup_execution(pipex);
	exit(1);
}

void	bash_error_continue(char *error_type)
{
	write(STDERR_FILENO, "bash: ", 6);
	perror(error_type);
}

void	child_error_exit(char *error_type)
{
	write(STDERR_FILENO, "bash: ", 6);
	perror(error_type);
	exit(1);
}

void	cmd_not_found(char *cmd, t_pipex *pipex)
{
	if (!cmd)
		write(STDERR_FILENO, "''", 2);
	else
		write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	cleanup_execution(pipex);
	exit(1);
}
