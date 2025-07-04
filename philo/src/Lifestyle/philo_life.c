/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:15:26 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/04 10:39:02 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	someone_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->just_die == TRUE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->table->death_mutex);
	return (0);
}

static void	day_by_day(t_philo *philo)
{
	//printf("ph[%d] t[%lu] EMPIEZA MI VIDA\n", philo->id, (get_time() - philo->table->actual_time) );
	//printf("%lu\n", (get_time() - philo->last_supper ));
	while (!someone_is_dead(philo))
	{
		if(someone_is_dead(philo))
			break;
		take_forks(philo);
		if (someone_is_dead(philo))
		{
			drop_forks(philo);
			break;
		}
		eat(philo);
		if (someone_is_dead(philo))
		{
			drop_forks(philo);
			break;
		}
		drop_forks(philo);
		sleep_loop(philo);
		if(someone_is_dead(philo))
			break;
		thinking(philo);
		if(someone_is_dead(philo))
			break;
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//printf("ph[%d] t[%lu] HE NACIDO\n", philo->id, (get_time() - philo->table->actual_time));
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat);
	//printf("%lu\n", (philo->last_supper - get_time()));
	day_by_day(philo);
	return (NULL);
}
