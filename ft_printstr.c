/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:18:23 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/03/09 19:41:17 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *str, int *counter)
{
	if (!str)
	{
		*counter += 6;
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (ft_printchar(*str, counter) == -1)
			return (-1);
		str++;
	}
	return (0);
}
