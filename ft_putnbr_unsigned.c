/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:40:42 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/18 09:13:03 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recursive(unsigned int nb)
{
	static int	i = 0;

	if (nb > 9)
	{
		ft_recursive(nb / 10);
	}
	i = i + ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	i = i + ft_recursive(nb);
	return (i);
}
