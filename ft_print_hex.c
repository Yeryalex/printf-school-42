/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:57:04 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/03/09 19:36:57 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int *counter, char *str)
{
	if (num >= 16)
	{
		if (ft_print_hex(num / 16, counter, str) == -1)
			return (-1);
		if (ft_print_hex(num % 16, counter, str) == -1)
			return (-1);
	}
	if (num < 16)
	{
		if (ft_printchar(str[num], counter) == -1)
			return (-1);
	}
	return (0);
}
