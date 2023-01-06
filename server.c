/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:44:51 by yochakib          #+#    #+#             */
/*   Updated: 2023/01/06 00:32:51 by yochakib         ###   ########.fr       */
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

void	signal_hundler(pid_t sig)
{
	static char *str;
	if (sig == SIGUSR1)
		str = ft_strjoin(str,"0");
	if (sig == SIGUSR2)
		str = ft_strjoin(str,"1");
	if (ft_strlen(str) == 8)
	{	
		ft_putchar(convert_to_decimal(ft_atoi(str)));
		if (str)
			free(str);
		str = NULL;
	}

}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n",pid);

	if ((signal(SIGUSR1, signal_hundler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	if ((signal(SIGUSR2, signal_hundler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	while (1)
		pause();
}