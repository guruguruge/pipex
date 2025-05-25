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

void	find_path(t_pipex *pipex)
{
	int	j;

	j = 0;
	get_rawpath(pipex);
	while (j < pipex->cmd_num)
	{
		if (pipex->cmds[j].args[0])
		{
			if (pipex->cmds[j].args[0][0] == '/')
				convert_fullpath(pipex, j);
			else
				convert_rawpath(pipex, j);
		}
		else
		{
			pipex->cmds[j].args[0] = NULL;
			pipex->cmds[j].no_cmd = 1;
		}
		j++;
	}
}

void	execute_cmds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_num)
	{
		if (i == 0)
			init_execution(pipex, i);
		else if (i == pipex->cmd_num - 1)
			final_execution(pipex, i);
		else
			general_execution(pipex, i);
		i++;
	}
	wait_children(pipex);
}

void	handle_args(int ac, char **av, char **envp, t_pipex *pipex)
{
	int	i;

	pipex->cmd_num = ac - 3;
	pipex->envp = envp;
	pipex->cmds = ft_calloc(pipex->cmd_num, sizeof(t_cmd));
	if (!pipex->cmds)
		cleanup_execution(pipex);
	i = 0;
	while (i < pipex->cmd_num)
	{
		pipex->cmds[i].args = ft_split(av[i + 2], ' ');
		if (!pipex->cmds[i].args)
			cleanup_execution(pipex);
		i++;
	}
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
	validate_files(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (write(2, "Invalid Input\n", 14), INVALID_INPUT);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		bash_error_exit("malloc", pipex);
	handle_args(argc, argv, envp, pipex);
	find_path(pipex);
	execute_cmds(pipex);
	cleanup_execution(pipex);
	if (pipex->error_flag)
		return (1);
	else
		return (0);
}
