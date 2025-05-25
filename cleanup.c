/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 20:12:13 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-18 20:12:13 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	write(STDERR_FILENO, "bash: ", 6);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	cleanup_execution(pipex);
	exit(1);
}

void	cleanup_execution(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i < pipex->cmd_num)
	{
		free(pipex->cmds[i].path);
		j = 0;
		while (pipex->cmds[i].args[j])
		{
			free(pipex->cmds[i].args[j]);
			j++;
		}
		free(pipex->cmds[i].args);
		i++;
	}
	i = 0;
	while (i < pipex->path_num)
	{
		free(pipex->all_paths[i]);
		i++;
	}
	free(pipex->all_paths);
	free(pipex->cmds);
	free(pipex);
}
