/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:19 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 16:02:06 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_green_light;

void	server_feedback_handler(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
		g_green_light = 1;
	else if (signum == SIGUSR2)
		write(1, "Message sent\n", 13);
}

void	send_the_char_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_green_light)
			;
		g_green_light = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	if (!client_error_main(argc, argv))
		return (print_client_usage_instructions(), -1);
	message = argv[2];
	pid = ft_atoi(argv[1]);
	if ((kill(pid, 0) == -1) || pid > 4194304)
		return (write(2, "Error, proccess doesn't exist\n", 30), -1);
	signal(SIGUSR1, server_feedback_handler);
	i = 0;
	while (message[i])
	{
		send_the_char_to_server(pid, message[i]);
		i++;
	}
	send_the_char_to_server(pid, '\0');
	return (0);
}
