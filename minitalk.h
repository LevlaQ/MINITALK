/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:50:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 19:16:31 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

int		client_error_main(int ac, char **av);
void	print_client_usage_instructions(void);
int		modified_atoi_limits(char *str);
int		validate_pid_input(char *pid);
void	send_the_char_to_server(int pid, char c);
void	server_feedback_handler(int signum);
void	signal_handler(int signal_type, siginfo_t *info, void *m_info);

#endif