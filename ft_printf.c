/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:09:04 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/23 19:50:47 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			*counter += ft_puthex(va_arg(arguments, int), *string);
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
	// int		i;

	counter = 0;
	// i = 0;
	va_start(arguments, string);
	if (!string)
		return (-1);
	while (*string)
	{
		if (*string == '%')
		{
			if (ft_perc_man(++string, arguments, &counter) == -1)
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
