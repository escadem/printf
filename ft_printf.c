/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:09:04 by eescat-l          #+#    #+#             */
/*   Updated: 2023/01/28 09:16:16 by eescat-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_placeholder(char c)
{
	char	*placeholder;
	int		i;

	i = 0;
	placeholder = "%%cspdiuxX";
	while (placeholder[i] != '\0')
	{
		if (placeholder[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_perc_man(char const *string, va_list args, size_t *counter)
{
	if (!*string || !ft_check_placeholder(*string))
		return (-1);
	else
	{
		if (*string == '%')
			*counter += ft_putchar('%');
		else if (*string == 'c')
			*counter += ft_putchar(va_arg(args, int));
		else if (*string == 's')
			*counter += ft_putstring(va_arg(args, char *));
		else if (*string == 'p')
		{
			write(1, "0x", 2);
			*counter += 2;
			*counter += ft_putpointer(va_arg(args, unsigned long), 'x');
		}
		else if (*string == 'd' || *string == 'i')
			*counter += ft_putdecimal(va_arg(args, int), *string);
		else if (*string == 'u')
			*counter += ft_putunsigned(va_arg(args, unsigned int));
		else if (*string == 'x' || *string == 'X')
			*counter += ft_puthex(va_arg(args, unsigned int), *string);
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
