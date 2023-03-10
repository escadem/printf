/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uunsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:54:25 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 09:03:41 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_hex_len(unsigned long n)
{
	unsigned int			length;
	unsigned long			nr;

	length = 0;
	if (n < 0)
	{
		length++;
		nr = n * (-1);
	}
	else
		nr = n;
	while ((nr / 16) > 0)
	{
		nr /= 16;
		length++;
	}
	return (length + 1);
}

char	*ft_hex_str(unsigned long int a, char chr)
{
	unsigned int		length;
	char				*str;
	unsigned long		nr;

	length = ft_hex_len(a);
	str = (char *) malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (a == 0)
		str[0] = '0';
	else
	{
		if (a < 0)
			nr = a * (-1);
			str[0] = '-';
		if (a > 0)
			nr = a;
		while (nr > 0)
		{
			str[--length] = ft_chardigit(nr % 16, chr);
			nr /= 16;
		}
	}
	return (str);
}

int	ft_puthex(unsigned int a, char chr)
{
	unsigned int	l;
	char			*str;

	str = ft_hex_str(a, chr);
	l = ft_putstring(str);
	free(str);
	return (l);
}

int	ft_putpointer(unsigned long a, char chr)
{
	unsigned int	l;
	char			*str;

	str = ft_hex_str(a, chr);
	l = ft_putstring(str);
	free(str);
	return (l);
}
