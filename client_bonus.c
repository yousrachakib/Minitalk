/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:07:00 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/14 16:17:27 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	message(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\n***WELL RECEIVED***\n");
	exit (0);
}

void	send_char(char c, int pid)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = c >> i-- & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	size_t	server_pid;
	int	i;

	if (ac != 3)
		return (ft_printf("Some this wrong arguments not enough!\n"));
	else
	{
		i = 0;
		server_pid = ftt_atoi(av[1]);
        signal(SIGUSR1, message);
		while (av[2][i])
		{
			send_char(av[2][i], server_pid);
			i++;
		}
		send_char(0, server_pid);
	}
	return (0);
}
