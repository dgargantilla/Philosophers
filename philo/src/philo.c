/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:01:17 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/16 14:59:39 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	create_table(t_table *table)
{
	table->forks = ft_calloc(table->n_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		print_error("Error al crear los tenedores");
	table->philos = ft_calloc(table->n_philos, sizeof(t_philo));
	if (!table->philos)
	{
		free(table->forks);
		print_error("Error al crear los philos");
	}
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	
}

int	main(int argc, char **argv)
{
	t_table table;

	memset(&table, 0, sizeof(t_table));
	table.nt_must_to_eat = -1;
	if (argc == 5 || argc == 6)
		parsing_init(&table, argv);
	else
		print_error("Numero de argumentos no valido");
	printf("Numero de philos: %d\n", table.n_philos);
	printf("Tiempo de muerte: %d\n", table.time_to_die);
	printf("Tiempo de comer: %d\n", table.time_to_eat);
	printf("Tiempo de dormir: %d\n", table.time_to_sleep);
	printf("Veces que tienen que comer: %d\n", table.nt_must_to_eat);
	return (0);
}