/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:47:15 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/30 12:52:37 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	take_forks(t_philo *philo)
{
	int nf_rigth;
	int nf_left;

	nf_rigth = philo->id % philo->table->n_philos;
	nf_left = philo->id;
	if (philo->table->n_philos > 1)
	{
		pthread_mutex_lock(&philo->table->philos[nf_rigth]);
		printer(philo->table, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->table->philos[nf_left]);
		printer(philo->table, "has taken a fork", philo->id);
	}
}

void	drop_forks(t_philo *philo)
{
	int nf_rigth;
	int nf_left;

	nf_rigth = philo->id % philo->table->n_philos;
	nf_left = philo->id;
	if (philo->table->n_philos != 1)
	{
		pthread_mutex_unlock(&philo->table->philos[nf_rigth]);
		pthread_mutex_unlock(&philo->table->philos[nf_left]);
	}
}