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
	int		no_cmd;
}			t_cmd;

typedef struct s_temp
{
	char	*cmd_temp;
	char	*cmd_j;
	char	*path_temp;
}			t_temp;

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

	int		error_flag;
}			t_pipex;

void		bash_error_exit(char *error_type, t_pipex *pipex);
void		bash_error_continue(char *error_type);
void		child_error_exit(char *error_type);

void		cmd_not_found(char *cmd);

void		cleanup_execution(t_pipex *pipex);

void		find_path(t_pipex *t_pipex);
void		get_rawpath(t_pipex *pipex);
void		validate_files(t_pipex *pipex);
void		convert_rawpath(t_pipex *pipex, int i);

void		execute_cmds(t_pipex *t_pipex);

void		init_execution(t_pipex *pipex, int i);
void		general_execution(t_pipex *pipex, int i);
void		final_execution(t_pipex *pipex, int i);
void		wait_children(t_pipex *pipex);

pid_t		pipe_and_fork(int *pipefd, t_pipex *pipex);
void		close_pipe(int pipe1, int pipe2);

void		handle_args(int ac, char **av, char **envp, t_pipex *pipex);

# define INVALID_INPUT 1
# define OUT_FILE_ERROR -1

#endif
