/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:32:10 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/23 19:41:38 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	return(ft_putstring(ft_defstr(a, chr,  10)));
	// return(ft_putstring(ft_itoa(a)));
	// return (ft_digit_lenght(a,10));
}

int	ft_putunsigned(int a)
{
	if (a < 0)
		a *= (-1);
	return (ft_putdigit(a, d, 10));
}

int	ft_puthex(int a, char chr)
{
	return (ft_putstring(ft_defstr(a, chr, 16)));
}
