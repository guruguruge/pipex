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

# include <stdlib.h>
# include <unistd.h>

char		**ft_split(char const *s, char c);

typedef struct s_cmd
{
	char	**args;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmds;
	int		cmd_num;

	char	**envp;

}			t_pipex;

#endif