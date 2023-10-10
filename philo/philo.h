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
# include <time.h>

//Parsing message

# define NUMBERS "Numbers of philosophers is invalid\n"
# define ZERO "Invalid arguments, must be in int array and bigger than 0\n"
# define TYPE "Error, arguments must be : number_of_philosophers, time_to_die, time_to_eat,\
	time_to_sleep and number_of_times_each_philosopher_must_eat(optional)\n"

//Philo message

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

// -fsanitize=thread

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		td;
	unsigned long	last_meal;
	int				id;
	pthread_mutex_t	*fork;
	int				nb_meals;
}	t_philo;

typedef struct s_data
{
	unsigned long	first_time;
	int				dead;
	int				finished;
	int				numbers;
	int				nb_must_eat;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
}	t_data;

//main.c
int				main(int ac, char **av);
t_data			*init_data(char **av);
void			*status_philo(void *arg);

//parsing.c
int				verif_arg(int ac, char **av);
t_philo			*parse_arg(char **av, t_philo *philo);
int				put_error(char *msg);
unsigned long	actual_time_ms(void);
void			wait_action(unsigned long waiting);

//utils.c
int				ft_strlen(char *str);
int				ft_atoi(char *nptr);
int				ft_strcmp(char *s1, char *s2);
void			put_msg(char *msg, int id, t_philo *philo);
unsigned long	get_actual_time(t_philo *philo);

//init_philo.c
void			create_philo(t_data *data, t_philo *philo);
void			is_death(t_philo *philo);
void			free_all(t_philo *philo);
int				finished_eat(t_philo *philo);

//routine.c
void			is_eating(t_philo *philo);
void			is_sleeping(t_philo *philo);
void			is_thinking(t_philo *philo);
void			lock_fork(t_philo *philo);
void			unlock_fork(t_philo *philo);

#endif