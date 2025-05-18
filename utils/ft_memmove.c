/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:20:21 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:20:21 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (ds < sr)
	{
		while (n--)
		{
			*ds++ = *sr++;
		}
	}
	else if (ds > sr)
	{
		ds += n;
		sr += n;
		while (n--)
			*(--ds) = *(--sr);
	}
	return (dest);
}
