/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:20:43 by cmichez           #+#    #+#             */
/*   Updated: 2023/09/05 11:20:43 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# define NUMBERS "Numbers of philosophers is invalid\n"
# define ZERO "Invalid arguments, must be bigger than 0\n"
# define TYPE "Error, argurments are : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep and number_of_times_each_philosopher_must_eat(optional)\n"

typedef struct s_philo
{
	pthread_t	tid;
} t_philo;

//main.c



//parsing.c
int		verif_arg(int ac, char **av);
void	put_error(char *msg);

//utils.c
int		ft_atoi(char *nptr);

#endif