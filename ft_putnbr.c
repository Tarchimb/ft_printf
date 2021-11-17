/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:40:42 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/17 12:23:19 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recursive(int nb)
{
	int	i;

	i = 0;
	if (nb < -9 || nb > 9)
	{
		i = ft_recursive(nb / 10);
	}
	if (nb < 0)
		i = i + ft_putchar(-(nb % 10) + '0');
	else
		i = i + ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		i = ft_putchar('-');
	i = i + ft_recursive(nb);
	return (i);
}
