/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:39:51 by dtunega           #+#    #+#             */
/*   Updated: 2024/06/11 15:03:15 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static char	*ft_strrev(char *str)
{
	char	temp;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

unsigned int	print_unsigned(unsigned int i)
{
	char	*s;
	int		l;

	s = ft_utoa(i);
	l = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (l);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[i++] = '0';
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

int	print_hex(unsigned long n)
{
	char		buffer[16];
	int			index;
	const char	*hex_chars = "0123456789abcdef";
	int			char_to_print;

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

int	print_pointer(void *ptr)
{
	unsigned long	p;
	int				chars_printed;

	chars_printed = 0;
	if (!ptr)
	{
		chars_printed += print_string("(nil)");
		return (chars_printed);
	}
	p = (unsigned long)ptr;
	chars_printed = 0;
	chars_printed += print_char('0');
	chars_printed += print_char('x');
	chars_printed += print_hex(p);
	return (chars_printed);
}
