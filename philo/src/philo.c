/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:01:17 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/06 17:06:08 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_tables table;

	memset(&table, 0, sizeof(t_tables));
	if (argc == 5 || argc == 6)
		parsing_init(&table, argv);
	else
		printf("Numero de argumentos no valido\n");
	return (0);
}