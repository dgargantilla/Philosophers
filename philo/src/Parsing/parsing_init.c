/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:23:29 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/06 17:09:04 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error()
{
	printf("Error\n");
	exit(1);
}

int	ft_isdigit(int c)
{
	if (!(c < '0' || c > '9'))
		return (1);
	return (0);
}

int	check_letrs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && (str[i] != '+'))
			return (1);
		i++;
	}
	return (0);
}

void	parsing_init(t_tables *table, char **args)
{
	int	i;

	i = 1;
	(void)table;
	while (args[i])
	{
		if (ft_atoi(args[i]) == 0)
			print_error();
		if (check_letrs(args[i]))
			print_error();
		else if (check_overflow(args[i]))
			print_error();
		i++;
	}
}