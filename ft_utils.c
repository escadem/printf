/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:47:22 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 09:02:44 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_chardigit(long int nr, char chr)
{
	char	*char_lower;
	char	*char_upper;

	char_lower = "0123456789abcdef";
	char_upper = "0123456789ABCDEF";
	if (chr == 'x' || chr == 'd' || chr == 'i')
		return (char_lower[nr]);
	else
		return (char_upper[nr]);
}
