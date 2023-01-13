/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/13 18:15:59 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message(int	sig)
{
	if (sig == SIGUSR1)
		ft_printf("**********{WELL RECEIVED}**********\n");
	exit (0);
}

void	send_signals(char c, int pid)
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
		usleep(500);
	}
}

int main(int ac, char **av)
{
	int server_pid;
	int i;
	
	if (ac != 3)
		return(ft_printf("few arguments!\n"));
	else
	{	i = 0;
		server_pid = ftt_atoi(av[1]);
		signal(SIGUSR1, message);
		while (av[2][i])
		{
			send_signals(av[2][i], server_pid);
			i++;
		}
		send_signals(0, server_pid);
		sleep(1);
	}
	return (0);
}