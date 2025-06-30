/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:40:05 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/30 12:43:12 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	printer(t_table *table, char *action, int id)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("%ld %d %s", (get_time() - table->actual_time),
			 id, action);
	pthread_mutex_unlock(&table->print_mutex);
}