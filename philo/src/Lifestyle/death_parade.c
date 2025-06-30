/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_parade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:34 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/26 12:36:28 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_parade(void *arg)
{
	/* esta funcion/proceso va a revisar si alguien muere
	 o si ha de terminarse el programa y hacer que todos
	 los philos paren su ejecuccion*/ 
	t_table	*reaper;

	reaper = (t_table *)arg;
	while (1)
	{
		
	}
}