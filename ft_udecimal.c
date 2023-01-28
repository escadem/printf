/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:42:45 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 07:51:44 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_decimal_len(long int n)
{
	unsigned int			length;
	unsigned long int		nr;

	length = 0;
	// printf("****[%u]\n", length);
	if (n < 0)
	{
		length++;
		nr = n * (-1);
	}
	else
		nr = n;
	while ((nr / 10) > 0)
	{
		nr /= 10;
		length++;
	}
	// printf("****[%u]\n", length);
	return (length + 1);
}

char	*ft_decimal_str(long int a, char chr)
{
	unsigned int		length;
	char				*str;
	long int			nr;

	// printf("******************\n");
	length = ft_decimal_len(a);
	// printf("****[%u]\n", length);
	//length = 16;
	str = (char *) malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0'; 
	// printf("*[%u]\n", length);
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
			//printf("*[%u]\n", length);
			str[--length] = ft_chardigit(nr % 10, chr);
			nr /= 10;
		}
	}
	return (str);
}

int	ft_putdecimal(long int a, char chr)
{
	unsigned int	l;
	char 			*str;
	str = ft_decimal_str(a, chr);
	l = ft_putstring(str);
	free(str);
	return (l);
	// return (ft_putstring(ft_defstr(a, chr, 10)));
}

int	ft_putunsigned(int a)
{
	unsigned int	u;
	
	u= (unsigned int)a;
	// if (a < 0)
	// 	a *= (-1);
	return (ft_putdecimal(u, 'd'));
}