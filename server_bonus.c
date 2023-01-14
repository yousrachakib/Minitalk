/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:06:25 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/14 16:13:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig, siginfo_t *info)
{
	static char	*str;
	static int	client_pid;

	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		if (str)
			free(str);
		str = 0;
	}
	if (sig == SIGUSR1)
		str = ftt_strjoin(str, "1");
	if (sig == SIGUSR2)
		str = ftt_strjoin(str, "0");
	if (ftt_strlen(str) == 8)
	{
		ftt_putchar(binary_to_decimal(ftt_atoi(str)));
		if (str)
			free (str);
        if (binary_to_decimal(ftt_atoi(str)) == 0)
			kill(client_pid, SIGUSR1);
		str = NULL;
	}
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Some thing is wrong with arguments\n");
		return (1);
	}
	act.sa_handler = (void *)signal_handler;
	server_pid = getpid();
	ft_printf("******server PID********\n");
	ft_printf("=====>%d\n", server_pid);
	sigaction(SIGUSR1, &act, NULL);
	(sigaction(SIGUSR2, &act, NULL));
	while (1)
		pause();
}