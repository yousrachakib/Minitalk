/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:44:08 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/14 16:13:05 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "printf/ft_printf.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

int		ftt_atoi(char *str);
size_t	ftt_strlen(char *str);
char	*ftt_strjoin(char *s1, char *s2);
void	ftt_putchar(char c);
int		binary_to_decimal(int binary);

#endif