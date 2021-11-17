/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:55:43 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/17 10:27:42 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr((char *)va_arg(arg, char *));
	if (c == 'c')
		count = ft_putchar((int)va_arg(arg, int));
	if (c == '%')
		count = ft_putchar('%');
	if (c == 'd' || c == 'i')
		count = ft_putnbr((int)va_arg(arg, int));
	if (c == 'u')
		count = ft_putnbr_unsigned((unsigned int)va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X' || c == 'p')
		count = ft_put_hexa((uintptr_t)va_arg(arg, uintptr_t), c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argptr, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = count + ft_print_arg(argptr, s[i + 1]);
			i += 2;
		}
		else
		{
			if (s[i] == '\n')
				count = count + ft_putchar('\n');
			else
				count = count + ft_putchar(s[i]);
			i++;
		}
	}
	va_end(argptr);
	return (count);
}

int	main(void)
{
	char			*i;
	int				c;
	unsigned int	u;

	i = "salut";
	c = 2147483647;
	u = c * 2;
	ft_printf("%d\n", ft_printf("string -->%s,purcent--> %%,char-->%c, int--> %d, unsigned int-->%u, address--> %p\n", i, c, c, u, &u));
	printf("%d\n", printf("string -->%s,purcent--> %%,char-->%c, int--> %d, unsigned int-->%u, address--> %p\n", i, c, c, u, &u));
}
