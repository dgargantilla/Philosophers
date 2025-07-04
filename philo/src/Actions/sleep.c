/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:00:30 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/01 12:24:35 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_loop(t_philo *philo)
{
	int sleep;
	int to_sleep;

	sleep = 0;
	pthread_mutex_lock(&philo->table->table_mutex);
	to_sleep = philo->table->time_to_sleep;
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->just_die == FALSE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		printer(philo->table, "is sleeping", philo->id);
		while (sleep <= to_sleep)
		{
			pthread_mutex_lock(&philo->table->death_mutex);
			if (philo->table->just_die == TRUE)
			{
				pthread_mutex_unlock(&philo->table->death_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->table->death_mutex);
			ft_usleep(1);
			sleep += 1;
		}
	}
}
