/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-17 18:29:29 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-17 18:29:29 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(t_pipex *t_pipex);
void	prepare_pipe(t_pipex *t_pipex);
void	execute_cmds(t_pipex *t_pipex);
void	cleanup_execution(t_pipex *t_pipex);

void	find_path(t_pipex *t_pipex)
{
}

void	prepare_pipe(t_pipex *t_pipex)
{
}

void	execute_cmds(t_pipex *t_pipex)
{
}

void	cleanup_execution(t_pipex *t_pipex)
{
}

void	handle_args(int ac, char **av, char **envp, t_pipex *pipex)
{
	int	i;

	pipex->cmd_num = ac - 3;
	pipex->envp = envp;
	pipex->cmds = malloc(sizeof(t_cmd) * pipex->cmd_num);
	i = 0;
	while (i < pipex->cmd_num)
	{
		pipex->cmds[i].args = ft_split(av[i + 2], ' ');
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (1);
	pipex = malloc(sizeof(t_pipex));
	handle_args(argc, argv, envp, pipex);
	find_path(pipex);
	prepare_pipe(pipex);
	execute_cmds(pipex);
	cleanup_execution(pipex);
	return (0);
}
