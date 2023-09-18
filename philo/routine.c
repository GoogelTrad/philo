/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:54:47 by cmichez           #+#    #+#             */
/*   Updated: 2023/09/12 11:54:47 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, t_data *data)
{
	put_msg(FORK, data->time, philo->id);
	if ()
}

void	is_eating(t_philo *philo, t_data *data)
{
	philo->eating = 1;
	put_msg(EAT, data->time, philo->id);
	philo->eating = 0;
}

void	status_philo(char *msg, t_philo *philo, t_data *data)
{
	data->time = actual_time_ms();
	if (ft_strcmp(msg, "EAT") == 0)
		is_eating(philo, data);
}
