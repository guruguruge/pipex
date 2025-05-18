/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 12:04:56 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-18 12:04:56 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_rawpath(t_pipex *pipex);
void	convert_rawpath(t_pipex *pipex, int i);

void	get_path_num(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->all_paths[i])
		i++;
	pipex->path_num = i;
}

void	get_rawpath(t_pipex *pipex)
{
	char	**envp;
	char	*raw_path;
	int		i;

	envp = pipex->envp;
	i = 0;
	while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	if (!envp[i])
		bash_error_exit("PATH not found", pipex);
	raw_path = ft_strdup(envp[i] + 5);
	if (!raw_path)
		bash_error_exit("malloc", pipex);
	pipex->all_paths = ft_split(raw_path, ':');
	free(raw_path);
	if (!pipex->all_paths)
		bash_error_exit("malloc", pipex);
	get_path_num(pipex);
}

void	convert_rawpath(t_pipex *pipex, int j)
{
	int		i;
	char	*cmd_temp;
	char	*cmd_j;
	char	*path_temp;

	cmd_j = pipex->cmds[j].args[0];
	cmd_temp = ft_strjoin("/", cmd_j);
	if (!cmd_temp)
		bash_error_exit("malloc", pipex);
	i = 0;
	while (i < pipex->path_num)
	{
		path_temp = ft_strjoin(pipex->all_paths[i], cmd_temp);
		if (!path_temp)
			bash_error_exit("malloc", pipex);
		if (!access(path_temp, X_OK))
		{
			pipex->cmds[j].path = path_temp;
			break ;
		}
		free(path_temp);
		i++;
	}
	free(cmd_temp);
	if (i != pipex->path_num)
		return ;
	bash_error_exit(cmd_j, pipex);
}

// void	check_access(t_pipex *pipex, int j)
// {
// 	int i;

// 	i = 0;
// 	while (i < pipex->path_num)
// 	{
// 		if (!access(pipex->all_paths[i], X_OK))
// 		{
// 			pipex->cmds[j].path = pipex->all_paths[i];
// 			return ;
// 		}
// 		i++;
// 	}
// }