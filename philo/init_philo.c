/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:20:48 by cmichez           #+#    #+#             */
/*   Updated: 2023/09/06 10:20:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->numbers)
	{
		pthread_create(&philo[i].td, NULL, status_philo, philo + i);
		i++;
	}
}

int	finished_eat(t_philo *philo)
{
	if (philo->data->nb_must_eat != 0)
	{
		if (philo->nb_meals < philo->data->nb_must_eat)
			return (0);
		philo->data->finished = 1;
		return (1);
	}
	return (0);
}

void	dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->numbers)
	{
		philo[i].data->dead = 1;
		philo[i].data->finished = 1;
		i++;
	}
}

void	is_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->data->numbers)
		{
			if (get_actual_time(philo) - philo[i].last_meal
				> philo->data->time_to_die)
			{
				put_msg(DEATH, philo[i].id, philo);
				dead(philo);
				return ;
			}
			i++;
		}
		if (finished_eat(philo))
			break ;
	}
}

void	free_all(t_philo *philo)
{
	int	i;
	int	max;

	i = 0;
	max = philo[0].data->numbers;
	while (i < max)
	{
		pthread_mutex_destroy(philo[i].fork);
		pthread_detach(philo[i].td);
		i++;
	}
}
