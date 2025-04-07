/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:50:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/07 11:28:45 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 200809L

/*
	Sigactionda posix kullanıyorum
*/

# include <signal.h>
# include <sys/signal.h> //Bunsuz çalışıp çalışmadığına bakarsın
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

int		client_error_main(int ac, char **av);
void	print_client_usage_instructions(void);
int		modified_atoi_limits(char *str);
int		validate_pid_input(const char *pid);
void	send_the_char_to_server(int pid, char c);
void	server_feedback_handler(int signum);

#endif