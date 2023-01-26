/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:47:22 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/26 20:16:31 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_digit_lenght(long int n, int base)
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
	while ((nr / base) > 0)
	{
		nr /= base;
		length++;
	}
	// printf("****[%u]\n", length);
	return (length + 1);
}

char	ft_chardigit(long int nr, char chr)
{
	char	*charchrx;
	char	*charchrX;

	charchrx = "0123456789abcdef";
	charchrX = "0123456789ABCDEF";

	// if (chr == 'x' || chr == 'd' || chr == 'i')
	// 	charchr = "0123456789abcdef";
	// else
	// 	charchr = "0123456789ABCDEF";
	// // if (chr == 'd' || chr == 'i')
	// // 	ft_memcpy(charchr, "0123456789", 11);
	// printf("*[%ld]\n", nr);
	if (chr == 'x' || chr == 'd' || chr == 'i')
		return (charchrx[nr]);
	else
		return (charchrX[nr]);
	// return 0;
}

char	*ft_defstr(long int a, char chr, int base)
{
	unsigned int		length;
	char				*str;
	long int			nr;

	// printf("******************\n");
	length = ft_digit_lenght(a, base);
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
			str[--length] = ft_chardigit(nr % base, chr);
			nr /= base;
		}
	}
	return (str);
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