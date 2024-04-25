/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:53:36 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/04/02 18:52:57 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(va_list va, char *str, int *counter)
{
	if (*str == 'c')
		return (ft_printchar(va_arg(va, int), counter));
	else if (*str == 's')
		return (ft_printstr(va_arg(va, char *), counter));
	else if (*str == 'p')
		return (ft_print_address(va_arg(va, void *), counter));
	else if (*str == 'd' || *str == 'i')
		return (ft_printdigit(va_arg(va, int), counter));
	else if (*str == 'u')
		return (ft_printdigit_u(va_arg(va, unsigned int), counter));
	else if (*str == 'x')
		return (ft_print_hex(va_arg(va, unsigned int), counter, HEX_LOWER));
	else if (*str == 'X')
		return (ft_print_hex(va_arg(va, unsigned int), counter, HEX_UPPER));
	else if (*str == '%')
	{
		if (ft_printchar('%', counter) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	arguments;
	int		counter;

	counter = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (ft_printchar(*format, &counter) == -1)
				return (-1);
		}
		else if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (ft_format(arguments, (char *)format, &counter) == -1)
				return (-1);
		}
		format++;
	}
	return (counter);
}
