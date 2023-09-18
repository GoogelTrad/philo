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
	t_data data;

	if (verif_arg(ac, av) == 0)
		return (0);
	parse_arg(&data, av);
	while(1)
		is_eating(data.philo, &data);
}
