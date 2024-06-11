/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:43 by dtunega           #+#    #+#             */
/*   Updated: 2024/06/11 15:35:02 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int				ft_printf(const char *s, ...);

unsigned int	print_unsigned(unsigned int i);

int				print_char(int c);

int				print_pointer(void *ptr);

int				print_hex(unsigned long n);

char			*ft_utoa(unsigned int n);

int				print_decimal(int f);

int				print_string(char *s);

int				print_char(int c);
#endif
