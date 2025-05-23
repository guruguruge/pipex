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
		pipex->error_flag = OUT_FILE_ERROR;
		close(fd);
		bash_error_continue(pipex->outfile);
	}
	close(fd);
	fd = open(pipex->infile, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		bash_error_exit(pipex->infile, pipex);
	}
	close(fd);
}
