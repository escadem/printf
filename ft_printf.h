/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:42:07 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 08:24:02 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>

//ft_printf
int				ft_check_placeholder(char c);
int				ft_perc_man(char const *string, va_list arguments, size_t *counter);
int				ft_printf(char const *string, ...);

//ft_uchar
int				ft_putchar(char c);
int				ft_putstring(char *str);

//ft_udecimal
unsigned int	ft_decimal_len(long int n);
char			*ft_decimal_str(long int a, char chr);
int				ft_putdecimal(long int a, char chr);
int				ft_putunsigned(int a);

//ft_utils
char			ft_chardigit(long int nr, char chr);

//ft_uunsigned
unsigned int	ft_hex_len(unsigned long n);
char			*ft_hex_str(unsigned long int a, char chr);
int				ft_puthex(unsigned int a, char chr);
int				ft_putpointer(unsigned long a, char chr);

//ft_upointer

// void			*ft_memcpy(void *dst, const void *src, size_t n);
// void			*ft_bzero(void *s, size_t n);
// void			*ft_calloc(size_t count, size_t size);

// unsigned int	ft_digit_lenght(long int n, int base);
// unsigned int	ft_digit_lenght_unsigned(unsigned long n, int base);
// char			ft_chardigit(long int nr, char chr);
// char			*ft_defstr(long int a, char chr, int base);
// char			*ft_defstrpointer(unsigned long int a, char chr, int base);

// int				ft_putchar(char c);
// int				ft_putstring(char *str);
// int				ft_putdigit(long int a, char chr);
// int				ft_putunsigned(int a);
// int				ft_puthex(unsigned int a, char chr);
// int				ft_putpointer(long int a);
// int				ft_putpuntero(unsigned long a, char chr);

// int				ft_printf(char const *string, ...);

#endif 