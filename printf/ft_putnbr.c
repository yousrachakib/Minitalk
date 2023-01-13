/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:59:24 by yochakib          #+#    #+#             */
/*   Updated: 2022/11/24 20:24:20 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = n * -1;
	}
	if (n <= 9)
		i += ft_putchar(n + '0');
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	put_unsigned_nbr(unsigned int num)
{
	unsigned int	rest;
	int				i;

	i = 0;
	rest = num % 10 + '0';
	num /= 10;
	if (num != 0)
		i += put_unsigned_nbr(num);
	i += ft_putchar(rest);
	return (i);
}
