/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-01 11:04:48 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-01 11:04:48 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_unltoa_base(uintptr_t n, int base, char alph_cap)
{
	char	*str;
	size_t	len;
	char	*base_digits;

	if (alph_cap == 'x')
		base_digits = "0123456789abcdef";
	else if (alph_cap == 'X')
		base_digits = "0123456789ABCDEF";
	if (n == 0)
		len = 1;
	else
		len = unllen_base(n, base);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = base_digits[n % base];
		n /= base;
	}
	return (str);
}

char	*ft_unitoa_base(unsigned int n, int base, char alph_cap)
{
	char	*str;
	size_t	len;
	char	*base_digits;

	if (alph_cap == 'x')
		base_digits = "0123456789abcdef";
	else if (alph_cap == 'X')
		base_digits = "0123456789ABCDEF";
	if (n == 0)
		len = 1;
	else
		len = unintlen_base(n, base);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = base_digits[n % base];
		n /= base;
	}
	return (str);
}

size_t	unllen_base(unsigned long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

size_t	unintlen_base(unsigned int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

// #include <stdio.h>

// void	test(unsigned int n, int base, char alph_cap)
// {
// 	char	*result;

// 	result = ft_itoa_base(n, base, alph_cap);
// 	if (result)
// 	{
// 		printf("n = %u, base = %d, alph_cap = '%c' -> \"%s\"\n", n, base,
// 			alph_cap, result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("n = %u, base = %d, alph_cap = '%c' -> NULL (error)\n", n, base,
// 			alph_cap);
// 	}
// }

// int	main(void)
// {
// 	// 基本テスト♠️
// 	test(0, 10, 'x');
// 	test(0, 16, 'x');
// 	test(0, 2, 'X');

// 	// 小さい数テスト♥️
// 	test(1, 2, 'x');
// 	test(10, 10, 'x');
// 	test(15, 16, 'x');
// 	test(15, 16, 'X');

// 	// 境界値テスト♦️
// 	test(255, 2, 'x');
// 	test(255, 8, 'x');
// 	test(255, 10, 'x');
// 	test(255, 16, 'X');

// 	// でかい数テスト♣️
// 	test(4294967295u, 10, 'x'); // UINT_MAX
// 	test(4294967295u, 16, 'x');
// 	test(4294967295u, 2, 'X');

// 	// 無効な base テスト♥️
// 	test(42, 1, 'x');
// 	test(42, 17, 'x');

// 	// 無効な alph_cap テスト♦️
// 	test(42, 10, 'y');

// 	return (0);
// }
