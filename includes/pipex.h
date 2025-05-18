/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-17 18:29:51 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-17 18:29:51 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	**args;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;

	t_cmd	*cmds;
	int		cmd_num;
	int		path_num;

	char	**envp;

	char	**all_paths;

	int		prev_pipefd[2];

}			t_pipex;

void		bash_error_exit(char *error_type, t_pipex *pipex);
void		child_error_exit(char *error_type);

void		cleanup_execution(t_pipex *pipex);

void		find_path(t_pipex *t_pipex);
void		get_rawpath(t_pipex *pipex);
void		convert_rawpath(t_pipex *pipex, int i);

void		execute_cmds(t_pipex *t_pipex);

void		init_execution(t_pipex *pipex, int i);
void		general_execution(t_pipex *pipex, int i);
void		final_execution(t_pipex *pipex, int i);
void		wait_children(t_pipex *pipex);

void		handle_args(int ac, char **av, char **envp, t_pipex *pipex);

# define INVALID_INPUT 1
# define MALLOC_FAIL 2

#endif
