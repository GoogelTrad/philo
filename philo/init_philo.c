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
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * (data->numbers));
	while(i < data->numbers)
	{
		pthread_create(&thread[i], NULL, status_philo, philo + i);
		i++;
	}
}

void	is_death(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numbers)
	{
		if (actual_time_ms() - philo[i].last_meal > data->time_to_die)
		{
			put_msg(DEATH, philo[i].id, philo);
			data->dead = 1;
			break ;
		}
		i++;
	}
}
