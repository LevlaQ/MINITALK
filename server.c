/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:48:01 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 14:46:42 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal_type, siginfo_t *info, void *m_info)
{
	(void)m_info; //parantez içinde void ne demek
	static char	c;
	static int	bit;
	pid_t		sender_pid;
	
	sender_pid = info->si_pid;
	if( signal_type == SIGUSR1)
		c |= (1 << bit); //c üzerine eklemeler yapıyor
	bit++; //her gelen sinyalde bit'i bir arttırıyor
	if (bit == 8)
	{
		if((unsigned char)c < 128) //ascii karakterleri harici basmasın
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(sender_pid, SIGUSR1);
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
