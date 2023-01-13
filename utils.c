/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:19:50 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/13 03:46:07 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ftt_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ftt_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ftt_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
    return(res);
}
int	binary_to_decimal(int binary)
{
	int	decimal;
	int	base;
	int	reminder;

	decimal = 0;
	base = 1;
	while (binary)
	{
		reminder = binary % 10;
		binary = binary / 10;
		decimal += reminder * base;
		base = base * 2;
	}
	return (decimal);
}

char	*ftt_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ftt_strlen(s1) + ftt_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
			str[i++] = s2[j++];
	str[ftt_strlen(s1) + ftt_strlen(s2)] = '\0';
	free(s1);
	return (str);
}