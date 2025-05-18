/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:24:07 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:24:07 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= (dst_len))
	{
		return ((src_len) + size);
	}
	else
	{
		while ((i < (size - dst_len - 1)) && (src[i]))
		{
			dst[(dst_len) + i] = src[i];
			i++;
		}
		dst[(dst_len) + i] = '\0';
		return ((dst_len) + (src_len));
	}
}
