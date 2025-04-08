/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:38 by gyildiz           #+#    #+#             */
/*   Updated: 2025/04/08 15:59:13 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	client_error_main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	if (!validate_pid_input(av[1]))
		return (0);
	return (1);
}

int	validate_pid_input(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	if (!modified_atoi_limits(pid))
		return (0);
	return (1);
}

int	modified_atoi_limits(char *str)
{
	int				i;
	int				sign;
	unsigned long	inte;

	i = 0;
	sign = 1;
	inte = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		inte = (inte * 10) + (str[i] - 48);
		i++;
		if (inte > 2147483647)
		{
			if (sign == 1)
				return (0);
			else if (inte > 2147483648)
				return (0);
		}
	}
	return (1);
}

void	print_client_usage_instructions(void)
{
	write(2, "ERROR! Correct usage is: ./client <PID> <message>\n", 50);
	write(2, "If spaces are used, message must be in quotation marks\n", 55);
}
