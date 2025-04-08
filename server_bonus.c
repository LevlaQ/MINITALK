/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:06 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 19:31:28 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk_bonus.h"

void	signal_handler(int signal_type, siginfo_t *info, void *m_info)
{
	static char	c;
	static int	bit;
	pid_t		sender_pid;

	(void)m_info;
	sender_pid = info->si_pid;
	if (signal_type == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			message_recieved(sender_pid);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(sender_pid, SIGUSR1);
}

void	message_recieved(int pid)
{
	write(1, "\nMessage received from client PID: ", 35);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	kill(pid, SIGUSR2);
	pid = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (42)
		pause();
	return (0);
}
