/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:59:08 by dtunega           #+#    #+#             */
/*   Updated: 2024/06/11 15:07:35 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(int f)
{
	char	*num;
	int		i;

	num = ft_itoa(f);
	i = ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	return (i);
}
