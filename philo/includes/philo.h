/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:57:44 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/30 15:10:05 by dgargant         ###   ########.fr       */
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
 #include <sys/time.h>

typedef struct s_philo
{
	int					id;
	long				death_time;
	long				last_supper;
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
	long				actual_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		table_mutex;
	pthread_t			the_reaper;
	t_philo				*philos;
}			t_table;

// Parsing

int	parsing_init(t_table *table, char **args);

int	check_overflow(char *nums);

int	ft_atoi(const char *str);

int	print_error(char *error);

// Actions

void	take_forks(t_philo *philo);

void	printer(t_table *table, char *action, int id);

void	drop_forks(t_philo *philo);

// lifestyle

void	*philo_life(void *arg);

// Utils

void	*ft_calloc(size_t count, size_t size);

long	get_time();

# endif