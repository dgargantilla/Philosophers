/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:47:15 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/04 10:54:20 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	just_a_fork(t_philo *philo, int nf_left, int nf_rigth)
{
	if (nf_left == nf_rigth)
	{
		printer(philo->table, "has taken a fork", philo->id);
		ft_usleep(philo->death_time);
		philo->im_dead = TRUE;
		printer(philo->table, "died", philo->id);
		return (1);
	}
	return (0);
}

void	take_forks(t_philo *philo)
{
	int nf_rigth;
	int nf_left;

	nf_rigth = philo->id % philo->table->n_philos;
	nf_left = philo->id - 1;
	if (just_a_fork(philo, nf_left, nf_rigth))
		return ;
	if (philo->table->n_philos > 1)
	{
		pthread_mutex_lock(&philo->table->forks[nf_rigth]);
		printer(philo->table, "has taken a fork", philo->id);
		//printf(" %d Intentando pillar un tenedor\n", philo->id);
		pthread_mutex_lock(&philo->table->forks[nf_left]);
		printer(philo->table, "has taken a fork", philo->id);
	}
}

void	drop_forks(t_philo *philo)
{
	int nf_rigth;
	int nf_left;

	nf_rigth = philo->id % philo->table->n_philos;
	nf_left = philo->id - 1;
	if (philo->table->n_philos != 1)
	{
		pthread_mutex_unlock(&philo->table->forks[nf_rigth]);
		pthread_mutex_unlock(&philo->table->forks[nf_left]);
	}
}