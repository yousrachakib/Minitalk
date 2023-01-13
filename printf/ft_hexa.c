/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:59:42 by yochakib          #+#    #+#             */
/*   Updated: 2022/11/25 20:00:56 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned	int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_hexa(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}

int	ft_hexxa(unsigned	int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		i += ft_hexxa(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}
