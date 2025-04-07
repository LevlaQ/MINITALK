/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:48:01 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/06 16:54:16 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal_type, siginfo_t *info, void *m_info)
{
	(void)m_info; //parantez içinde void ne demek
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask); //Engellenecek sinyal yok
	sa.sa_flags = SA_RESTART | SA_SIGINFO; //Sinyal kesintisi gerçekleşirse sistem çağrısını yeniden başlat + belirli tipteki handler kullan
	if(sigaction(SIGUSR1, &sa, NULL) == -1 \
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1); //stdout'a yazıyı yazdırmaya çalışıyorum
	write(1, "\n", 1);
	while(42)
		pause();
	return (0);
}