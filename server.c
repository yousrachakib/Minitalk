/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:57:04 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/13 19:17:27 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int checking, siginfo_t *info)
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
	if (checking == SIGUSR1)
		str = ftt_strjoin(str, "1");
	if (checking == SIGUSR2)
		str = ftt_strjoin(str, "0");
	if (ftt_strlen(str) == 8)
	{
		ftt_putchar(binary_to_decimal(ftt_atoi(str)));
		if (str)
			free (str);
		str = NULL;
	}
}

int	main(void)
{
	pid_t server_pid;
	struct sigaction act;

	server_pid = getpid();
	ft_printf("******server PID********\n");
	ft_printf("=====>%d\n",server_pid);
	act.sa_handler = (void *)signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while(1)
		pause();
}