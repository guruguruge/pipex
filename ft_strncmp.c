/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:24:57 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:24:57 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!s1[i] || !s2[i])
			return (0);
		i++;
	}
	return (0);
}

// #include <string.h>

// int	main(void)
// {
// 	printf("比較1: %d\n", ft_strncmp("abcdef", "abcee", 3)); // 0
// 	printf("比較2: %d\n", ft_strncmp("abc", "abd", 0));      // 'c' - 'd' = -1
// 	printf("比較3: %d\n", ft_strncmp("ab", "", 0));          //
// 	printf("比較1: %d\n", strncmp("abcdef", "abcee", 3));    // 0
// 	printf("比較2: %d\n", strncmp("abc", "abd", 0));
// 	printf("比較3: %d\n", strncmp("ab", "", 0));
// }