/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:44:51 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/09 21:56:30 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

int    convert_to_decimal(int binary)
{
    int    decimal;
    int    base;
    int    rem;

    decimal = 0;
    base = 1;
    while (binary != 0)
    {
        rem = binary % 10;
        decimal = decimal + rem * base;
        binary = binary / 10;
        base = base * 2;
    }
    if (decimal > 127 || decimal < 0)
    {
        write(1, "\nError Recieving the signal\n", 28);
        exit(0);
    }
    else
        return (decimal);
}

void	signal_hundler(pid_t sig, siginfo_t	*info)
{
	static char *str;
	static pid_t	client_pid;
	
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		str = 0;
	}
	if (sig == SIGUSR1)
		str = ft_strjoin(str,"0");
	if (sig == SIGUSR2)
		str = ft_strjoin(str,"1");
	if (ft_strlen(str) == 8)
	{	
		ftt_putchar(convert_to_decimal(ft_atoi(str)));
		if (str)
			free(str);
		str = NULL;
	}

}

int	main(int argc, char	**argv)
{
	pid_t				pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("ERROR CHECK YOUR ARGC\n");
		exit(1);
	}
	act.sa_handler = (void *)signal_hundler;
	pid = getpid();
	ft_printf("%d\n",pid);
	if ((sigaction(SIGUSR1, &act, NULL)) < 0)
		write(1, "Error recieving the signal\n", 27);
	if ((sigaction(SIGUSR2, &act, NULL)) < 0)
		write(1, "Error recieving the signal\n", 27);
	while (1)
		pause();
}