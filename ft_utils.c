/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:47:22 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 07:56:12 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
