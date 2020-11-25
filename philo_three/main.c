/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:13:40 by flavon            #+#    #+#             */
/*   Updated: 2020/11/25 23:28:06 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_sem_init(t_state *state)
{
	sem_unlink("forks");
	sem_unlink("time");
	sem_unlink("out");
	sem_unlink("death");
	sem_unlink("waiter");
	sem_unlink("philo_died");
	if ((state->forks =
		sem_open("forks", O_CREAT, 0660, state->count_philo)) < 0)
		return (0);
	if ((state->time = sem_open("time", O_CREAT, 0660, 1)) < 0)
		return (0);
	if ((state->out = sem_open("out", O_CREAT, 0660, 1)) < 0)
		return (0);
	if ((state->death = sem_open("death", O_CREAT, 0660, 1)) < 0)
		return (0);
	if ((state->waiter = sem_open("waiter", O_CREAT, 0660, 1)) < 0)
		return (0);
	if ((state->philo_died = sem_open("philo_died", O_CREAT, 0660, 1)) < 0)
		return (0);
	return (1);
}

int		ft_argv_check(char **argv, int argc, t_state *state)
{
	int						i;

	i = -1;
	if ((state->count_philo = ft_atoi(argv[1])) < 2 ||
		!(state->time_die = ft_atoi(argv[2])) ||
		!(state->time_eat = ft_atoi(argv[3])) ||
		!(state->time_sleep = ft_atoi(argv[4])) ||
		!(state->philo_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1))
		return (0);
	if (!ft_sem_init(state))
		return (0);
	return (1);
}

void	philo_two_start(t_state *state)
{
	pid_t				phi;
	t_philo				philo[state->count_philo];
	int					fork_philo[state->count_philo];
	int					i;

	i = 0;
	sem_wait(state->philo_died);
	while (i < state->count_philo)
	{
		phi = fork();
		if (phi == 0)
		{
			philo[i].id = i;
			philo[i].state = state;
			philo[i].philo_must_eat = state->philo_must_eat;
			start_simulation(&philo[i]);
			exit(0);
		}
		else
			fork_philo[i++] = phi;
	}
	sem_wait(state->philo_died);
	i = -1;
	while (++i < state->count_philo)
		kill(fork_philo[i], SIGKILL);
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
	state.is_dead = 0;
	philo_two_start(&state);
	sem_close(state.forks);
	sem_close(state.waiter);
	sem_close(state.death);
	sem_close(state.out);
	sem_close(state.time);
	sem_close(state.philo_died);
	return (0);
}
