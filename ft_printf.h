/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <yrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:30:46 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/03/09 19:43:35 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);
int		ft_printchar(char c, int *counter);
int		ft_printstr(char *str, int *counter);
int		ft_printdigit(int n, int *counter);
int		ft_printdigit_u(unsigned int n, int *counter);
int		ft_print_hex(unsigned int num, int *counter, char *str);
int		ft_print_address(void *ptr, int *counter);

#endif
