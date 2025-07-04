/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:04:45 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/03 11:30:55 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eating_loop(t_philo *philo)
{
	int	eat;
	int table_eat;

	eat = 0;
	pthread_mutex_lock(&philo->table->table_mutex);
	table_eat = philo->table->time_to_eat;
	pthread_mutex_unlock(&philo->table->table_mutex);
	while (eat <= table_eat)
	{
		pthread_mutex_lock(&philo->table->death_mutex);
		if (philo->table->just_die == TRUE)
		{
			pthread_mutex_unlock(&philo->table->death_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->death_mutex);
		ft_usleep(1);
		eat += 1;
	}
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->just_die == FALSE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		printer(philo->table, "is eating", philo->id);
		pthread_mutex_lock(&philo->table->table_mutex);
		philo->table->meals++;
		philo->death_time = (get_time() - philo->last_supper)
			+ philo->table->time_to_die;
		philo->last_supper = get_time();
		pthread_mutex_unlock(&philo->table->table_mutex); 
		if (eating_loop(philo))
			return ;
	}
	else
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return ;
	}
}
