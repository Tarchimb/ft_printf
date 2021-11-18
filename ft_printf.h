/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:08:30 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/18 09:12:52 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_print_arg(va_list arg, char c);
int	ft_put_hexa(unsigned long long nb, char c);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
#endif
