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

t_philo	*parse_arg(char **av, t_philo *philo)
{
	int	i;
	t_data *data;
	pthread_mutex_t *fork;
	pthread_mutex_t	write;

	i = 0;
	data = malloc(sizeof(t_data));
	data->numbers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->first_time = actual_time_ms();
	data->dead = 0;
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
	philo = malloc(sizeof(t_philo) * (data->numbers));
	fork = malloc(sizeof(pthread_mutex_t) * data->numbers);
	while (i <= data->numbers)
	{
		pthread_mutex_init(&fork[i], 0);
		i++;
	}
	pthread_mutex_init(&write, 0);
	i = 0;
	while (i < data->numbers)
	{
		philo[i].fork = fork;
		philo[i].write = &write;
		philo[i].id = i + 1;
		philo[i].nb_meals = 0;
		philo[i].data = data;
		i++;
	}
	return (philo);
}

unsigned long	actual_time_ms(void)
{
	struct timeval	t;
	
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	wait_action(unsigned long waiting)
{
	unsigned long	diff;
	
	diff = actual_time_ms();
	while (actual_time_ms() - diff <= waiting)
		usleep(500);
}