/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:15:20 by mrehberg          #+#    #+#             */
/*   Updated: 2022/12/06 09:22:06 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_print(int *parity_bit, int *bit, unsigned char *msg, int si_pid)
{
	*parity_bit = *parity_bit % 2;
	if (*parity_bit == *bit)
	{
		write(1, msg, 1);
		*parity_bit = 0;
		*msg = 0;
		kill(si_pid, SIGUSR1);
	}
	else
	{
		*parity_bit = 0;
		*msg = 0;
		kill(si_pid, SIGUSR2);
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{	
	static int				count = 0;
	static unsigned char	msg = 0;
	static int				parity_bit = 0;
	int						bit;

	if (sig == SIGUSR1)
		bit = 1;
	if (sig == SIGUSR2)
		bit = 0;
	(void) context;
	count++;
	if (count < 9)
	{
		msg = msg << 1;
		if (sig == SIGUSR1)
		{
			msg = msg + 1;
			parity_bit++;
		}
	}
	else
	{
		count = 0;
		msg_print(&parity_bit, &bit, &msg, info -> si_pid);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		return (1);
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		return (1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (2);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (2);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("listening...\n");
	while (1)
		pause();
	return (0);
}
