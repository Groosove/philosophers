/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:13:40 by flavon            #+#    #+#             */
/*   Updated: 2020/11/25 23:07:23 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_argv_check(char **argv, int argc, t_state *state)
{
	int						i;
	static pthread_mutex_t	death = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	output = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	philo_time = PTHREAD_MUTEX_INITIALIZER;

	i = -1;
	if ((state->count_philo = ft_atoi(argv[1])) < 2 ||
		!(state->time_die = ft_atoi(argv[2])) ||
		!(state->time_eat = ft_atoi(argv[3])) ||
		!(state->time_sleep = ft_atoi(argv[4])) ||
		!(state->philo_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1))
		return (0);
	state->death = death;
	state->out = output;
	state->time = philo_time;
	pthread_mutex_destroy(&death);
	pthread_mutex_destroy(&output);
	pthread_mutex_destroy(&philo_time);
	return (1);
}

void	philo_one_start(t_state *state)
{
	pthread_mutex_t		fork[state->count_philo];
	t_philo				philo[state->count_philo];
	pthread_t			thread_philo[state->count_philo];
	int					i;

	i = -1;
	while (++i < state->count_philo)
		pthread_mutex_init(&fork[i], NULL);
	state->forks = fork;
	state->is_dead = 0;
	i = -1;
	while (++i < state->count_philo)
	{
		philo[i].id = i;
		philo[i].state = state;
		philo[i].philo_must_eat = state->philo_must_eat;
		pthread_create(&thread_philo[i], NULL, start_simulation, &philo[i]);
	}
	i = -1;
	while (++i < state->count_philo)
		pthread_join(thread_philo[i], NULL);
	i = -1;
	while (++i < state->count_philo)
		pthread_mutex_destroy(&state->forks[i]);
}

int		main(int argc, char **argv)
{
	t_state	state;

	if (argc < 5 || argc > 6)
	{
		ft_putstr("Wrong count arguments\n");
		return (1);
	}
	if (!ft_argv_check(argv, argc, &state))
	{
		ft_putstr("Invalid arguments\n");
		return (1);
	}
	philo_one_start(&state);
	pthread_mutex_destroy(&state.death);
	pthread_mutex_destroy(&state.out);
	pthread_mutex_destroy(&state.time);
	return (0);
}
