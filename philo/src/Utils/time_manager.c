/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:16:18 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/04 10:58:13 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct timeval	actual_time;
	long			time;

	time = 0;
	gettimeofday(&actual_time, NULL);
	time = (actual_time.tv_sec * 1000) +
			(actual_time.tv_usec / 1000);
	return (time);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(100);
	return (0);
}