/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:44:51 by yochakib          #+#    #+#             */
/*   Updated: 2022/12/28 22:09:22 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

int    convert_to_decimal(int binary)
{
    int    decimal;
    int    base;
    int    rem;
    int    num;

    decimal = 0;
    base = 1;
    num = binary;
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

void	signal_hundler(pid_t sig)
{
	static char *str;
	if (sig == SIGUSR1)
		str = ft_strjoin(str,"0");
	if (sig == SIGUSR2)
		str = ft_strjoin(str,"1");
	if (strlen(str) == 8)
	{	
		ft_putchar(convert_to_decimal(ft_atoi(str)));
		str = NULL;
	}

}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%d\n",pid);

	if (signal(SIGUSR1,signal_hundler) < 0)
		write(2, "Hello\n", 6);
	signal(SIGUSR2,signal_hundler);
	while (1)
		pause();
}