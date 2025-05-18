/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:21:07 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:21:07 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	free_all(size_t i, char **result, size_t **word_se)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
	free(word_se[0]);
	free(word_se[1]);
}

static int	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		flag;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if ((flag) && !(s[i] == c))
		{
			count++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static void	ft_get_start_end(char const *s, char c, size_t **st_en)
{
	size_t	i;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		st_en[0][word] = i;
		while (s[i] && s[i] != c)
			i++;
		st_en[1][word] = i - 1;
		word++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	*wd_se[2];
	size_t	i;
	char	**result;

	count = ft_countwords(s, c);
	wd_se[0] = ft_calloc(count, sizeof(size_t));
	wd_se[1] = ft_calloc(count, sizeof(size_t));
	if (!wd_se[0] || !wd_se[1])
		return (NULL);
	ft_get_start_end(s, c, wd_se);
	result = (char **)malloc((count + 1) * (sizeof(char *)));
	if (!result)
		return (free(wd_se[0]), free(wd_se[1]), NULL);
	i = 0;
	while (i < count)
	{
		result[i] = ft_substr(s, wd_se[0][i], wd_se[1][i] - wd_se[0][i] + 1);
		if (!result[i])
			return ((free_all(i, result, wd_se), NULL));
		i++;
	}
	result[count] = NULL;
	return (free(wd_se[0]), free(wd_se[1]), result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **result;
// 	int i = 0;

// 	result = ft_split(" ", 'a');

// 	if (!result)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}

// 	printf("Splitted result:\n");
// 	while (result[i])
// 	{
// 		printf("[%d]: \"%s\"\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	return (0);
// }