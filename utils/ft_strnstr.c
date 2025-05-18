/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 05:25:11 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 05:25:11 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len) {
  size_t i;
  size_t j;

  if (!*little)
    return ((char *)big);
  i = 0;
  while (i < len && (big[i])) {
    j = 0;
    while ((i + j < len) && (little[j]) && (little[j] == big[i + j]))
      j++;
    if (little[j] == '\0')
      return ((char *)&big[i]);
    i++;
  }
  return (NULL);
}
