/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:39 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/03/09 19:48:53 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printdigit_u(unsigned int n, int *counter)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
		num = n * (-1);
	else
		num = n;
	if (num > 9)
	{
		if (ft_printdigit(num / 10, counter) == -1)
			return (-1);
		if (ft_printdigit(num % 10, counter) == -1)
			return (-1);
	}
	else
	{
		if (ft_printchar(num + '0', counter) == -1)
			return (-1);
	}
	return (0);
}
