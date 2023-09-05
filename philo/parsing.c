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

void	put_error(char *msg)
{
	printf("%s", msg);
}

int	verif_arg(int ac, char **av)
{
	int	i;

	i = 2;
	if (ac < 4 || ac > 5)
	{
		put_error(TYPE);
		return (0);
	}
	if (ft_atoi(av[1]) < 1)
	{
		put_error(NUMBERS);
		return (0);
	}
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0)
		{
			put_error(ZERO);
			return (0);
		}
		i++;
	}
	return (1);
}