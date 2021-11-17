/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:24:17 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/17 12:16:03 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned long long nb, char c)
{
	char		*base;
	char		*base2;
	int			count;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	count = 0;
	if (nb > 16)
		count = ft_put_hexa(nb / 16, c);
	if (nb < 16 && c == 'p')
		count = count + ft_putstr("0x");
	if (c == 'X')
		count = count + ft_putchar(base2[nb % 16]);
	else
		count = count + ft_putchar(base[nb % 16]);
	return (count);
}
