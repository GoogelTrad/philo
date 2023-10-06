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
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->data = malloc(sizeof(t_data));
	if (verif_arg(ac, av) == 0)
		return (0);
	philo = parse_arg(av, philo);
	create_philo(philo->data, philo);
	is_death(philo);
	free_all(philo);
}
