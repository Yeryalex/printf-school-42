/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:32:28 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/03/09 19:43:38 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printdigit(int n, int *counter)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		if (ft_printchar('-', counter) == -1)
			return (-1);
	}
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
