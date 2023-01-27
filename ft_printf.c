/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:09:04 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/26 21:07:51 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"
#include "ft_printf.h"

static int	ft_check_placeholder(char c)
{
	char	*placeholder;
	int		i;

	i = 0;
	// ft_memcpy(placeholder, "%%cspdiuxX", 9);
	placeholder = "%%cspdiuxX";
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
			*counter += ft_putchar(va_arg(arguments, int));
		else if (*string == 's')
			*counter += ft_putstring(va_arg(arguments, char *));
		else if (*string == 'p')
		{
			write(1, "0x", 2);
			*counter += 2;
			*counter += ft_puthex(va_arg(arguments, long), 'x');
			// *counter += ft_putpointer(va_arg(arguments, long));
		}
		else if (*string == 'd' || *string == 'i')
			*counter += ft_putdigit(va_arg(arguments, int), *string);
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

	counter = 0;
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

// int main()
// {
// 	// char a = 'a';
// 	// char *p_a = &a;
// 	int i = -170;
// 	long l;
// 	l = i;
// 	printf ("\n\n%ld___%lu___%lx___\n\n",l,l,l);
// 	printf("prueba\n");
// 	ft_printf("prueba\n");
// 	printf("i = %i\n", 15);
// 	ft_printf("i = %i\n", 15);
// 	printf("c = %%\n");
// 	ft_printf("c = %%\n");
// 	printf("printf = %d\n", 0);
// 	ft_printf("ft_printf = %d\n", 0);
// 	printf("printf = %d\n", -17);
// 	ft_printf("ft_printf = %d\n", -17);
// 	printf("printf = %X\n", -1);
// 	ft_printf("ft_printf = %X\n", -1);
// 	printf("puntero printf = %p\n", &i);
// 	ft_printf("%p\n", &i);
// 	ft_printf("puntero ft_printf = %p\n", &i);
// 	printf("%c\n", 'a');
// 	ft_printf("%c\n", 'a');
// }
