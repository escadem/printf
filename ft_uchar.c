/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:32:10 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 08:56:44 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *str)
{
	int	i;

	if (!str)
		return (ft_putstring("(null)"));
	i = 0;
	while (*str)
	{
		write(1, str, 1);
		i++;
		str++;
	}
	return (i);
}
