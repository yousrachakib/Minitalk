/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:58:27 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/05 19:50:57 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

int	ft_atoi(char *string);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ftt_putchar(char c);



#endif