/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:48:22 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 12:42:00 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t green_light;

void	server_feedback_handler(int signum) //Karşı taraftan sinyalin gelmesini bekliyor
{
	(void)signum;
	if (signum == SIGUSR1)
		green_light = 1;
}

void	send_the_char_to_server(int pid, char c) //PID ve karakteri sinyal ile iletebilmek için alıyor
{
	int	bit;

	bit = 0;
	while(bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1); //bit 1 ise SIGUSR1 gönder
		else
			kill(pid, SIGUSR2); //bit 0 ise SIGUSR2 gönder
		while(!green_light)
			;
		green_light = 0;
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
		return(write(2, "Error, proccess doesn't exist\n", 30), -1);
	signal(SIGUSR1, server_feedback_handler);
	i = 0;
	while(message[i])
	{
		send_the_char_to_server(pid, message[i]);
		i++;
	}
	send_the_char_to_server(pid, '\0'); //Mesajın bittiğine dair satır sonu karakteri gönder
	return (0);
}