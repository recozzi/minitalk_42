/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:18:48 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/22 15:27:12 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "Libft/libft.h"

static int	ft_invalid_pid(char *str)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(str);
	if (pid <= 0)
	{
		ft_printf("\033[0;31mError: invalid PID\033[0m\n");
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			ft_printf("\033[0;31mError: invalid PID\033[0m\n");
			return (1);
		}
	}
	return (0);
}

static void	ft_recieved_msg(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
	{
		write(1, "\033[0;32mMessage received successfully\033[0m", 36);
		write(1, "\n", 1);
	}
}

static void	ft_send_msg(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		c >>= 1;
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int					i;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("\033[0;31mError: invalid arguments\033[0m\n");
		exit(1);
	}
	if (ft_invalid_pid(argv[1]) != 0)
		exit(1);
	i = 0;
	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = ft_recieved_msg;
	sigaction(SIGUSR1, &sa, 0);
	while (argv[2][i])
	{
		ft_send_msg(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	ft_send_msg(ft_atoi(argv[1]), '\0');
	ft_send_msg(ft_atoi(argv[1]), '\n');
	return (0);
}
