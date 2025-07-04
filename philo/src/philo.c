/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:01:17 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/04 11:06:02 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_table(t_table *table)
{
	int	i;

	i = 0;
	pthread_join(table->the_reaper, NULL);
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	free(table->forks);
	free(table->philos);
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_create(&table->philos[i].thread, NULL,
			philo_life, &table->philos[i]);
		i++;
	}
}

void	create_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].last_supper = get_time();
		table->philos[i].death_time = table->time_to_die;
		table->philos[i].im_dead = FALSE;
		i++;
	}
}

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
	pthread_mutex_init(&table->table_mutex, NULL);
	create_philos(table);
}

int	main(int argc, char **argv)
{
	t_table table;

	ft_memset(&table, 0, sizeof(t_table));
	table.nt_must_to_eat = -1;
	table.just_die = FALSE;
	table.actual_time = get_time();
	if (argc == 5 || argc == 6)
	{
		if (parsing_init(&table, argv))
			return (1);
	}
	else
		return (print_error("Numero de argumentos no valido"));
	create_table(&table);
	init_philos(&table);
	pthread_create(&table.the_reaper, NULL,
			death_parade , &table);
	destroy_table(&table);
	//printf("Numero de philos: %d\n", table.n_philos);
	//printf("Tiempo de muerte: %d\n", table.time_to_die);
	//printf("Tiempo de comer: %d\n", table.time_to_eat);
	//printf("Tiempo de dormir: %d\n", table.time_to_sleep);
	//printf("Veces que tienen que comer: %d\n", table.nt_must_to_eat);
	return (0);
}
