/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:57:44 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/16 14:21:00 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	struct s_table		*table;
}			t_philo;

typedef struct s_table
{
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nt_must_to_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		print_mutex;
	t_philo				*philos;
}			t_table;

// Parsing

void	parsing_init(t_table *table, char **args);

int		check_overflow(char *nums);

int		ft_atoi(const char *str);

void	print_error(char *error);

// Utils

void	*ft_calloc(size_t count, size_t size);

# endif