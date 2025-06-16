/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:53:05 by dgargant          #+#    #+#             */
/*   Updated: 2025/06/11 09:38:37 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - 48);
		if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
			return (nb * neg);
		i++;
	}
	return (1);
}
long long	ft_atoll(const char *str)
{
	size_t		i;
	int			neg;
	long long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - 48);
		if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
			return (nb * neg);
		i++;
	}
	return (0);
}

int	check_len(char *nums)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nums[i] == '+')
		i++;
	while (nums[i] == '0')
		i++;
	while (nums[i])
	{
		i++;
		count++;
	}
	if (count >= 11)
		return (1);
	return (0);
}

int	check_overflow(char *nums)
{
	if (check_len(nums))
		return (1);
	else if (ft_atoi(nums) != ft_atoll(nums))
		return (1);
	return (0);
}