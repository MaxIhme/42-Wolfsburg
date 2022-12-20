/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:15:23 by mrehberg          #+#    #+#             */
/*   Updated: 2022/12/05 12:27:33 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_util	g_util;

/**
 * @brief receives from server if client should send the same byte
 * or the next byte
 */
void	client_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR2)
		g_util.send_again = 1;
	if (sig == SIGUSR1)
		g_util.send_next = 1;
	(void) *info;
	(void) *context;
}

/**
 * @brief 
 * SIGUSR1 is a 1
 * SIGUSR2 is a 0
 * 
 * sends 8 bits and then a parity bit
 * if uneven no of 1's, send 1, else send 0 -> parity bit
 * @param c character to send
 * @param pid process ID of server
 */
void	send_byte(unsigned int c, int pid)
{
	int				run;
	unsigned int	ce;
	int				parity_bit;

	parity_bit = 0;
	run = 8;
	ce = c;
	while (run)
	{
		if (ce >> (run -1) & 1)
		{
			kill(pid, SIGUSR1);
			parity_bit++;
		}
		else
			kill(pid, SIGUSR2);
		run--;
		usleep(100);
	}
	parity_bit = parity_bit % 2;
	if (parity_bit % 2)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	process_message(char *msg, int pid)
{
	int	run;

	run = 0;
	while (msg[run])
	{
		send_byte(msg[run], pid);
		while (!(g_util.send_next || g_util.send_again))
			usleep(50);
		if (g_util.send_again)
			run--;
		g_util.send_again = 0;
		g_util.send_next = 0;
		run++;
	}
	send_byte('\n', pid);
	send_byte('\0', pid);
	usleep(500);
	if (g_util.send_next)
		ft_printf("\nThe message has been delivered\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	g_util.send_next = 0;
	g_util.send_again = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(2, &"Error\n", 6);
		ft_printf("Please give me a valid PID and then a message as argument\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &client_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (2);
	process_message(argv[2], pid);
	return (0);
}
