/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:25:18 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:25:18 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	char_c;
	char			*pointer;

	pointer = NULL;
	i = 0;
	char_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == char_c)
			pointer = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (pointer);
}

// int	main(void)
// {
// 	char *str = "bananannnnn";
// 	char *loc = ft_strrchr(str, 'c');
// 	char *loc2 = strrchr(str, 'c');

// 	printf("最後の 'a' の位置以降: %s\n", loc);
// 	printf("最後の 'a' の位置以降: %s\n", loc2);
// }