/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:21:14 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:21:14 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	char_c;

	i = 0;
	char_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == char_c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "Helllo";
// 	int c = 'a';

// 	char *location1 = ft_strchr(str, c);
// 	char *location2 = strchr(str, c);

// 	printf("ft_strchr: %s\n", location1);
// 	printf("strchr   : %s\n", location2);
// }