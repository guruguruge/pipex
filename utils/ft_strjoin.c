/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:23:57 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:23:57 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	total_len;
	char	*j_str;
	size_t	i;

	s1_len = ft_strlen(s1);
	total_len = s1_len + ft_strlen(s2);
	j_str = (char *)malloc((total_len + 1) * (sizeof(char)));
	if (!j_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		j_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < total_len - s1_len)
	{
		j_str[s1_len + i] = s2[i];
		i++;
	}
	j_str[total_len] = '\0';
	return (j_str);
}
