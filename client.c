/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:11:18 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/05 22:01:04 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	send_char(char c, pid_t pid)
{
	int i;
	char	q;


	i = 7;
	while(i >= 0)
	{
		q = c >> i-- & 1;
		if (q == 0)
			kill(pid,SIGUSR1);
		else if (q == 1)
			kill(pid,SIGUSR2);
		usleep(500);
	}
}


int	main(int	argc,char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		pid_t pid = ft_atoi(argv[1]);
		if (pid == 0)
			return (0);
		while(argv[2][i] != '\0')
		{
			send_char(argv[2][i], pid);
			i++;
		}
		if (argv[2][i] == '\0')
		{
			send_char(argv[2][i], pid);
			sleep(1);
		}
		return (0);
	}
	return (1);
}