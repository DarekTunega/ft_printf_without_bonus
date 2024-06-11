/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:42:02 by dtunega           #+#    #+#             */
/*   Updated: 2024/06/11 15:10:09 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_hex_upper(unsigned long n)
{
	char		buffer[16];
	int			index;
	const char	*hex_chars;
	int			char_to_print;

	hex_chars = "0123456789ABCDEF";
	char_to_print = 0;
	if (n == 0)
	{
		char_to_print += print_char('0');
		return (char_to_print);
	}
	index = 0;
	while (n > 0)
	{
		buffer[index++] = hex_chars[n % 16];
		n /= 16;
	}
	while (index > 0)
	{
		char_to_print += print_char(buffer[--index]);
	}
	return (char_to_print);
}

int	print_string(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (i);
}

static int	printftype(va_list args, const char str)
{
	int	char_to_print;

	if (!args || !str)
		return (0);
	char_to_print = 0;
	if (str == 'c')
		char_to_print += print_char(va_arg(args, int));
	else if (str == 'd' || str == 'i')
		char_to_print += print_decimal(va_arg(args, int));
	else if (str == '%')
		char_to_print += print_char('%');
	else if (str == 's')
		char_to_print += print_string(va_arg(args, char *));
	else if (str == 'p')
		char_to_print += print_pointer(va_arg(args, void *));
	else if (str == 'x')
		char_to_print += print_hex(va_arg(args, unsigned int));
	else if (str == 'X')
		char_to_print += print_hex_upper(va_arg(args, unsigned int));
	else if (str == 'u')
		char_to_print += print_unsigned(va_arg(args, unsigned int));
	return (char_to_print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	va_start(args, str);
	i = 0;
	chars_printed = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			chars_printed += printftype(args, str[i + 1]);
			i++;
		}
		else
			chars_printed += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
