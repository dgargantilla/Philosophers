/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:30:30 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/01 12:38:35 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->just_die == FALSE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		printer(philo->table, "is thinking", philo->id);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return ;
	}
}
