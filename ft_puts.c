/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:32:10 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/26 20:25:59 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write(1, str, 1);
		i++;
		str++;
	}
	return (i);
}

int	ft_putdigit(int a, char chr)
{
	unsigned int	l;
	char 			*str;
	str = ft_defstr(a, chr, 10);
	l = ft_putstring(str);
	free(str);
	return (l);
	// return (ft_putstring(ft_defstr(a, chr, 10)));
}

int	ft_putunsigned(int a)
{
	if (a < 0)
		a *= (-1);
	return (ft_putdigit(a, 'd'));
}

int	ft_puthex(long int a, char chr)
{
	unsigned int	l;
	char 			*str;

	// printf("----------------\n");
	str = ft_defstr(a, chr, 16);
	l = ft_putstring(str);
	free(str);
	return (l);
	// return (ft_putstring(ft_defstr(a, chr, 16)));
}

// int	ft_putpointer(long int a)
// {
// 	return (ft_putstring(ft_defstr(a, 'x', 16)));
// }
