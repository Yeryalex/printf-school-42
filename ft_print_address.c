/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:17:48 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/04/02 18:53:10 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_print_hex_p(unsigned long num, int *counter, char *str)
{
	if (num >= 16)
	{
		ft_print_hex_p(num / 16, counter, str);
		ft_print_hex_p(num % 16, counter, str);
	}
	if (num < 16)
	{
		if (ft_printchar(str[num], counter) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_address(void *ptr, int *counter)
{
	unsigned long	value;

	if (!ptr)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		*counter += 3;
		return (0);
	}
	value = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	*counter += 2;
	if (ft_print_hex_p(value, counter, HEX_LOWER))
		return (-1);
	return (0);
}
