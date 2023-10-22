/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:57 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/22 15:29:15 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "Libft/libft.h"

static int	ft_power(int base, int power)
{
	int	result;
	int	i;

	if (power == 0)
		return (1);
	i = 1;
	result = base;
	while (i < power)
	{
		result *= base;
		i++;
	}
	return (result);
}

static void	ft_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	result;
	static int	client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		result += ft_power(2, bit);
	bit++;
	if (bit == 8)
	{
		if (result == 0)
		{
			if (kill(client_pid, SIGUSR1) == -1)
				exit(1);
			bit = 0;
			result = 0;
		}
		write(1, &result, 1);
		bit = 0;
		result = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[0;31mError: invalid arguments\033[0m\n");
		exit(1);
	}
	ft_printf("\033[94mServer pid: %d\033[0m\n", getpid());
	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = ft_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
