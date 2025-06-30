/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:23:29 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/25 13:01:38 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *error)
{
	printf("%s\n", error);
	return (1);
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

void	take_nums(t_table *table, char *arg, int i)
{
	if (i == 1)
		table->n_philos = ft_atoi(arg);
	if (i == 2)
		table->time_to_die = ft_atoi(arg);
	if (i == 3)
		table->time_to_eat = ft_atoi(arg);
	if (i == 4)
		table->time_to_sleep = ft_atoi(arg);
	if (arg && i == 5)
		table->nt_must_to_eat = ft_atoi(arg);
}

int	parsing_init(t_table *table, char **args)
{
	int	i;

	i = 1;
	(void)table;
	while (args[i])
	{
		if (i == 1 && ft_atoi(args[i]) == 0)
			return (print_error("Se necesita al menos un philo"));
		if (check_letrs(args[i]))
			return (print_error("Argumento no valido"));
		else if (check_overflow(args[i]))
			return (print_error("Numero incorrecto"));
		take_nums(table, args[i], i);
		i++;
	}
	return (0);
}