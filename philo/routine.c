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
		pthread_mutex_unlock(&philo->fork[0]);
	else
		pthread_mutex_unlock(&philo->fork[philo->id + 1]);
	pthread_mutex_unlock(&philo->fork[philo->id]);
}

void	lock_fork(t_philo *philo)
{
	if (philo->id == philo->data->numbers)
		pthread_mutex_lock(&philo->fork[0]);
	else
		pthread_mutex_lock(&philo->fork[philo->id + 1]);
	if (philo->data->dead == 1)
		return ;
	put_msg(FORK, philo->id, philo);
	pthread_mutex_lock(&philo->fork[philo->id]);
	if (philo->data->dead == 1)
		return ;
	put_msg(FORK, philo->id, philo);
}

void	is_eating(t_philo *philo)
{
	lock_fork(philo);
	if (philo->data->dead == 1)
		return ;
	put_msg(EAT, philo->id, philo);
	philo->last_meal = get_actual_time(philo);
	wait_action(philo->data->time_to_eat);
	philo->nb_meals++;
	unlock_fork(philo);
}

void	is_thinking(t_philo *philo)
{
	if (philo->data->dead == 1)
		return ;
	put_msg(THINK, philo->id, philo);
}

void	is_sleeping(t_philo *philo)
{
	if (philo->data->dead == 1)
		return ;
	put_msg(SLEEP, philo->id, philo);
	wait_action(philo->data->time_to_sleep);
}
