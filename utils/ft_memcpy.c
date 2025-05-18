/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:20:14 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:20:14 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	if ((!dest && !src) && n > 0)
		return (NULL);
	i = 0;
	char_dest = (unsigned char *)dest;
	char_src = (const unsigned char *)src;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return ((void *)dest);
}
