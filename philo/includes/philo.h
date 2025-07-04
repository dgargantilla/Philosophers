/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:57:44 by dgargant          #+#    #+#             */
/*   Updated: 2025/07/03 11:18:49 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdint.h>
# include <sys/time.h>

# define FALSE 0
# define TRUE 1

typedef struct s_philo
{
	int					id;
	int					im_dead;
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
	int					meals;
	int					just_die;
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

void	eat(t_philo *philo);

int		eating_loop(t_philo *philo);

void	sleep_loop(t_philo *philo);

void	thinking(t_philo *philo);

// lifestyle

void	*philo_life(void *arg);

void	*death_parade(void *arg);

// Utils

void	*ft_calloc(size_t count, size_t size);

long	get_time();

int	ft_usleep(size_t time);

void	*ft_memset(void *b, int c, size_t len);

# endif