/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:42:07 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/26 20:25:10 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef LIBFTPRINTF_H
// # define LIBFTPRINTF_H
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

unsigned int	ft_digit_lenght(long int n, int base);
char			ft_chardigit(long int nr, char chr);
char			*ft_defstr(long int a, char chr, int base);

int				ft_putchar(char c);
int				ft_putstring(char *str);
int				ft_putdigit(int a, char chr);
int				ft_putunsigned(int a);
int				ft_puthex(long int a, char chr);
int				ft_putpointer(long int a);

#endif 