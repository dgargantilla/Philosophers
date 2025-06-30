/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:16:18 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/30 12:41:45 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct timeval	actual_time;
	long			time;

	time = ((gettimeofday(actual_time.tv_sec, NULL) * 1000) +
			(gettimeofday(actual_time.tv_usec, NULL) / 1000));
	return (time);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	while ((get_time() - start) < time)
		usleep(200);
	return (0);
}