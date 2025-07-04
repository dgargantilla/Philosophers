/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:40:05 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/03 11:59:17 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	printer(t_table *table, char *action, int id)
{
	pthread_mutex_lock(&table->death_mutex);
	if (table->just_die == FALSE)
	{
		pthread_mutex_unlock(&table->death_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d %s\n", (get_time() - table->actual_time),
				 id, action);
		pthread_mutex_unlock(&table->print_mutex);
	}
	else
	{
		pthread_mutex_unlock(&table->death_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d %s\n", (get_time() - table->actual_time),
				 id, action);
		pthread_mutex_unlock(&table->print_mutex);
	}
}
