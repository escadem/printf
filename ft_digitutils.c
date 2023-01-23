/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:47:22 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/23 19:48:39 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


unsigned int	ft_digit_lenght(int n, int base)
{
	unsigned int		length;
	unsigned int		nr;

	length = 0;
	if (n < 0)
	{
		length += 1;
		nr = n * (-1);
	}
	else
		nr = n;
	while ((nr / base) > 0)
	{
		nr /= base;
		length++;
	}
	return (length + 1);
}

// char	*ft_itoa(int n)
// {
// 	unsigned int		length;
// 	char				*str;
// 	unsigned int		nr;

// 	length = ft_digit_lenght(n, 10);
// // printf("longitud int = %d\n", length);
// 	str = ft_calloc(length + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	str[length] = '\0';
// 	if (n == 0)
// 		str[0] = '0';
// 	else
// 	{
// 		if (n < 0)
// 			nr = n * (-1);
// 			str[0] = '-';
// 		if (n > 0)
// 			nr = n;
// 		while (nr > 0)
// 		{
// 			str[--length] = (nr % 10) + '0';
// 			nr /= 10;
// 		}
// 	}
// 	return (str);
// }

char	ft_charhex(int nr, char chr)
{
	char	charhex[17];

	if (chr == 'd' || chr == 'i')
		ft_memcpy(charhex, "0123456789", 11);
	else if (chr == 'x')
		ft_memcpy(charhex, "0123456789abcdef", 17);
	else
		ft_memcpy(charhex, "0123456789ABCDEF", 17);
	return (charhex[nr]);
}

char	*ft_defstr(unsigned int a, char chr, int base)
{
	unsigned int		length;
	char				*str;
	unsigned int		nr;

	length = ft_digit_lenght(a, base);
	str = ft_calloc(length + 1, sizeof(char));
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
			str[--length] = ft_charhex(nr % base, chr);
			nr /= base;
		}
	}
	return (str);
}
