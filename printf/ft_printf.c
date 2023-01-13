/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:42:12 by yochakib          #+#    #+#             */
/*   Updated: 2022/11/25 20:14:03 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_check(char const c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	detect_format(char format, va_list	num_args)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_putchar(va_arg(num_args, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(num_args, char *));
	else if (format == 'p')
		counter += ft_putmemoryaddress(va_arg(num_args, unsigned long));
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(num_args, int));
	else if (format == 'u')
		counter += put_unsigned_nbr(va_arg(num_args, unsigned int));
	else if (format == 'x')
		counter += ft_hexa(va_arg(num_args, unsigned int));
	else if (format == 'X')
		counter += ft_hexxa(va_arg(num_args, unsigned int));
	else if (format == '%')
		counter += ft_putchar(format);
	else
		counter += ft_putchar(format);
	return (counter);
}

int	ft_printf(const	char *format, ...)
{
	int			num_args;
	va_list		args;

	va_start(args, format);
	num_args = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			num_args += detect_format(*format, args);
		}
		else
			num_args += ft_putchar(*format);
		if (*format == '\0')
			break ;
		format++;
	}
	return (num_args);
}
