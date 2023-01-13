/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:00:00 by yochakib          #+#    #+#             */
/*   Updated: 2022/11/25 20:07:22 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(unsigned	long int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_x(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}

int	ft_putmemoryaddress(unsigned long nbr)
{
	int	c;

	ft_putstr("0x");
	c = (ft_x(nbr) + 2);
	return (c);
}
