/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:25:55 by cmichez           #+#    #+#             */
/*   Updated: 2023/09/05 12:25:55 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_error(char *msg)
{
	printf("%s", msg);
	return (0);
}

int	verif_arg(int ac, char **av)
{
	int	i;

	i = 2;
	if (ac < 4 || ac > 5)
		return (put_error(TYPE));
	if (ft_atoi(av[1]) < 1 && ft_strlen(av[1]) > 9)
		return (put_error(NUMBERS));
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0 && ft_strlen(av[i]) > 9)
			return (put_error(ZERO));
		i++;
	}
	return (1);
}

void	parse_arg(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->numbers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
	data->philo = malloc(sizeof(t_philo) * (data->numbers + 1));
	while (i < data->numbers)
	{
		pthread_mutex_init(&data->philo[i].fork, NULL);
		data->philo[i].id = i + 1;
		data->philo[i].eating = 0;
		data->philo[i].thinking = 0;
		data->philo[i].dead = 0;
		data->philo[i].sleeping = 0;
		i++;
	}
	data->philo[i].id = 0;
}