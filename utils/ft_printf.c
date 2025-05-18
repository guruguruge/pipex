/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 07:54:24 by sguruge           #+#    #+#             */
/*   Updated: 2025-04-29 07:54:24 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	error_handle(va_list *word)
{
	va_end(*word);
	return (-1);
}

int	print_word(char format, int *word_num)
{
	int	io_error;

	io_error = write(1, &format, 1);
	if (io_error == -1)
		return (0);
	(*word_num)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	word;
	size_t	i;
	int		word_num;

	va_start(word, format);
	i = 0;
	word_num = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (handle_conversion(format[i + 1], &word, &word_num))
				i += 2;
			else
				return (error_handle(&word));
		}
		else if (print_word(format[i], &word_num))
			i++;
		else
			return (error_handle(&word));
	}
	va_end(word);
	return (word_num);
}

int	handle_conversion(char format, va_list *word, int *word_num)
{
	int	io_error;

	io_error = 0;
	if (format == 'c')
		*word_num += print_char(word, &io_error);
	else if (format == 's')
		*word_num += print_str(word, &io_error);
	else if ((format == 'd') || (format == 'i'))
		*word_num += print_deci(word, &io_error);
	else if ((format == 'x') || (format == 'X'))
		*word_num += print_hex(word, &io_error, format);
	else if (format == 'u')
		*word_num += print_unsigned(word, &io_error);
	else if (format == 'p')
		*word_num += print_address(word, &io_error);
	else if (format == '%')
	{
		io_error = write(1, "%", 1);
		(*word_num)++;
	}
	else if (io_error == -1)
		return (0);
	else
		return (0);
	return (1);
}

// // ft_printfの実行を標準のprintfと比較するテスト用関数
// void	test_printf(const char *format, ...)
// {
// 	va_list args1, args2;
// 	va_start(args1, format);
// 	va_start(args2, format);
// 	// For ft_printf
// 	printf("===== ft_printf Output =====\n");
// 	vprintf(format, args1); // Use this temporarily to compare functionality
// 	printf("\n");
// 	// For standard printf
// 	printf("===== printf Output =====\n");
// 	vprintf(format, args2);
// 	printf("\n");
// 	va_end(args1);
// 	va_end(args2);
// }

// int	main(void)
// {
// 	// テストケース1: 基本的な文字列と整数
// 	test_printf(" NULL %s NULL ", NULL);

// 	// テストケース2: 16進数（小文字）

// 	// テストケース3: 0の表示
// 	test_printf("Zero as decimal: %d, Zero as hex: %x\n", 0, 0);

// 	// テストケース4: ポインタの表示（アドレスの形式）
// 	int val = 42;
// 	test_printf("Pointer address: %p\n", (void *)&val);

// 	// テストケース5: 数字の負の値
// 	test_printf("Negative decimal: %d, Negative hex: %x\n", -42, -42);

// 	// テストケース7: %のエスケープ（%%）
// 	test_printf("Escaped percent: %%\n");

// 	// テストケース8: 複数の引数
// 	test_printf("Multiple args: %d, %s, %x\n", 123, "Hello", 255);

// 	// テストケース9: 大文字と小文字での表示
// 	test_printf("Hex small: %x, Hex large: %X\n", 123456, 123456);

// 	// テストケース10: 未知の書式指定子（error)
// 	test_printf("Invalid specifier: %z\n");

// 	return (0);
// }

// #include "../includes/libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = printf("%");
// 	printf(" %i\n", i);
// 	j = ft_printf("%");
// 	printf(" %i\n", j);
// 	return (0);
// }
