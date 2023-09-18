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
# include <sys/time.h>

//Parsing message

# define NUMBERS "Numbers of philosophers is invalid\n"
# define ZERO "Invalid arguments, must be in int array and bigger than 0\n"
# define TYPE "Error, arguments must be : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep and number_of_times_each_philosopher_must_eat(optional)\n"

//Philo message

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

typedef struct s_philo
{
	pthread_t		*t1;
	int				id;
	pthread_mutex_t	fork;
	int				thinking;
	int				sleeping;
	int				eating;
	int				dead;
} t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*tid;
	size_t			time;
	int				numbers;
	int				nb_must_eat;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
} t_data;

//main.c
int		main(int ac, char **av);


//parsing.c
int		verif_arg(int ac, char **av);
void	parse_arg(t_data *data, char **av);
int		put_error(char *msg);
size_t	actual_time_ms(void);

//utils.c
int		ft_strlen(char *str);
int		ft_atoi(char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	put_msg(char *msg, size_t time, int id);

//init_philo.c
void	create_philo(t_philo *philo);

//routine.c
void	is_eating(t_philo *philo, t_data *data);
void	status_philo(char *msg, t_philo *philo, t_data *data);

#endif