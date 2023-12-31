/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:21:58 by cmichez           #+#    #+#             */
/*   Updated: 2023/09/05 12:21:58 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (verif_arg(ac, av) == 0)
		return (0);
	philo = parse_arg(av);
	create_philo(philo->data, philo);
	is_death(philo);
	free(philo->fork);
	free(philo->data);
	free(philo);
}

t_data	*init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->numbers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->first_time = actual_time_ms();
	data->finished = 0;
	data->dead = 0;
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
	return (data);
}

void	*status_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_actual_time(philo);
	if (philo->id % 2 == 1)
		wait_action(20);
	while (philo->data->finished == 0)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
