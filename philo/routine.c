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

void	unlock_fork(t_philo *philo)
{
	if (philo->id == philo->data->numbers)
		pthread_mutex_unlock(&philo->fork[1]);
	else
		pthread_mutex_unlock(&philo->fork[philo->id + 1]);
	pthread_mutex_unlock(&philo->fork[philo->id]);
}

void	lock_fork(t_philo *philo)
{
	if (philo->id == philo->data->numbers)
		pthread_mutex_lock(&philo->fork[1]);
	else
		pthread_mutex_lock(&philo->fork[philo->id + 1]);
	put_msg(FORK, philo->id, philo);
	pthread_mutex_lock(&philo->fork[philo->id]);
	put_msg(FORK, philo->id, philo);
}

void	is_eating(t_philo *philo)
{
	lock_fork(philo);
	if (philo->data->finished == 1)
		return ;
	put_msg(EAT, philo->id, philo);
	philo->last_meal = get_actual_time(philo);
	wait_action(philo->data->time_to_eat);
	philo->nb_meals++;
	unlock_fork(philo);
}

void	is_thinking(t_philo *philo)
{
	if (philo->data->finished == 1)
		return ;
	put_msg(THINK, philo->id, philo);
}

void	is_sleeping(t_philo *philo)
{
	if (philo->data->finished == 1)
		return ;
	put_msg(SLEEP, philo->id, philo);
	wait_action(philo->data->time_to_sleep);
}

void	*status_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_actual_time(philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->data->finished == 0)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
