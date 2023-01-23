/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:09:04 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/18 21:44:39 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libftprintf.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i ++;
	}
	return (dst);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) 0;
		i ++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count > SIZE_MAX / size)
		return (NULL);
	p = (void *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	return (ft_bzero(p, count * size));
}

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

char	*ft_itoa(int n)
{
	unsigned int		length;
	char				*str;
	unsigned int		nr;

	length = ft_digit_lenght(n, 10);
// printf("longitud int = %d\n", length);
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		if (n < 0)
			nr = n * (-1);
			str[0] = '-';
		if (n > 0)
			nr = n;
		while (nr > 0)
		{
			str[--length] = (nr % 10) + '0';
			nr /= 10;
		}
	}
	return (str);
}

char	ft_charhex(int nr, char chr)
{
	char	charhex[17];
	
	if (chr == 'x')
		ft_memcpy(charhex, "0123456789abcdef", 17);
	else
		ft_memcpy(charhex, "0123456789ABCDEF", 17);
	return (charhex[nr]);
}

char	*ft_strhex(unsigned int a, char chr)
{
	unsigned int		length;
	char				*str;
	unsigned int		nr;

	length = ft_digit_lenght(a, 16);
// printf("longitud hex = %d\n", length);
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
			str[--length] = ft_charhex(nr % 16, chr);
			nr /= 16;
		}
	}
	return (str);
}

/*
----------------------------------------------------------------------------------------
*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstring(char *str)
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

int	ft_putdigit(int a)
{
	return(ft_putstring(ft_itoa(a)));
	// return (ft_digit_lenght(a,10));
}

int	ft_putunsigned(int a)
{
	if (a < 0)
		a *= (-1);
	return (ft_putdigit(a));
}

int	ft_puthex(int a, char chr)
{
	return (ft_putstring(ft_strhex(a, chr)));
}

static int	ft_check_placeholder(char c)
{
	char	placeholder[9];
	int		i;

	i = 0;
	ft_memcpy(placeholder, "cspdiuxX", 9);
	while (placeholder[i] != '\0')
	{
		if (placeholder[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_perc_man(char const *string, va_list arguments, size_t *counter)
{
	if (!*string || !ft_check_placeholder(*string))
		return (-1);
	else
	{
		if (*string == '%')
			*counter += ft_putchar('%');
		else if (*string == 'c')
		{
			*counter += ft_putchar(va_arg(arguments, int));
		}
		else if (*string == 's')
			*counter += ft_putstring(va_arg(arguments, char *));
		// else if (*string == 'p')
		// 	*counter += ft_putpointer(va_arg(arguments, char *));
		else if (*string == 'd' || *string == 'i')
			*counter += ft_putdigit(va_arg(arguments, int));
		else if (*string == 'u')
			*counter += ft_putunsigned(va_arg(arguments, unsigned int));
		else if (*string == 'x' || *string == 'X')
			*counter += ft_puthex(va_arg(arguments, long), *string);
	}
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list	arguments;
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(arguments, string);
	if (!string)
		return (-1);
	while (*string)
	{
		if (*string == '%')
		{
			i = ft_perc_man(++string, arguments, &counter);
			if (i == -1)
				return (-1);
		}
		else if (*string != '%')
		{
			ft_putchar(*string);
			counter++;
		}
		string++;
	}
	va_end(arguments);
	return (counter);
}

int main()
{
	// char a = 'a';
	// char *p_a = &a;
	
	// printf("prueba\n");
	// ft_printf("prueba\n");
	// printf("i = %i\n", 15);
	// ft_printf("i = %i\n", 15);
	// printf("c = %%\n");
	// ft_printf("%i\n", -1701234);
	printf("printf = %X\n", 170000000);
	ft_printf("ft_printf %X\n", 170000000);
	printf("printf = %X\n", -170000000);
	ft_printf("ft_printf %X\n", -170000000);
	// printf("puntero printf = %p\n", p_a);
	// printf("%c\n", 'a');
	// ft_printf("%c\n", 'a');
}
