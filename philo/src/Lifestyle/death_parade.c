/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_parade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:34 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/03 12:44:41 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	kill_someone(t_philo *philo)
{
	if (get_time() - philo->death_time > philo->last_supper)
	{
		printer(philo->table, "died", philo->id);
		philo->im_dead = TRUE;
	}
}*/

static int	someone_dead(t_philo *philo)
{
	//kill_someone(philo);
	if (get_time() - philo->death_time > philo->last_supper)
	{
		printer(philo->table, "died", philo->id);
		philo->im_dead = TRUE;
	}
	if (philo->im_dead == TRUE)
	{
		pthread_mutex_lock(&philo->table->death_mutex);
		philo->table->just_die = TRUE;
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	return (0);
}


void	*death_parade(void *arg)
{
	t_table	*table;
	int 	i;
	int		n;
	
	table = (t_table *)arg;
	pthread_mutex_lock(&table->table_mutex);
	n = table->n_philos;
	pthread_mutex_unlock(&table->table_mutex);
	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (someone_dead(&table->philos[i]))
				return (NULL);
		}
	}
	return (NULL);
}