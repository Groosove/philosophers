/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:35:29 by flavon            #+#    #+#             */
/*   Updated: 2020/11/25 23:31:43 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_philo_sleep(int time)
{
	long start_time;

	start_time = ft_time();
	while (ft_time() - start_time < time)
		usleep(1);
}

void	ft_philo_eat(t_philo *philo)
{
	int fork;

	fork = (philo->id + 1) % philo->state->count_philo;
	if (philo->id % 2 == 0)
		take_fork(philo, philo->id, fork, 1);
	else
		take_fork(philo, fork, philo->id, 1);
	write_message(philo, "start eating\n");
	pthread_mutex_lock(&philo->state->time);
	philo->lunch_time = ft_time();
	pthread_mutex_unlock(&philo->state->time);
	ft_philo_sleep(philo->state->time_eat);
	if (philo->state->count_philo % 2 == 0)
		take_fork(philo, philo->id, fork, 0);
	else
		take_fork(philo, fork, philo->id, 0);
}

void	*ft_check_dead(void *phi)
{
	t_philo *philo;

	philo = (t_philo *)phi;
	while (1)
	{
		pthread_mutex_lock(&philo->state->time);
		if (ft_time() - philo->lunch_time > philo->state->time_die)
			break ;
		pthread_mutex_unlock(&philo->state->time);
	}
	pthread_mutex_unlock(&philo->state->time);
	if (!philo->philo_must_eat)
		return (NULL);
	write_message(philo, RED"is dead\n"RESET);
	philo->state->is_dead = 1;
	pthread_mutex_unlock(&philo->state->death);
	return (NULL);
}

void	*start_simulation(void *phi)
{
	t_philo		*philo;
	pthread_t	dead;

	philo = (t_philo *)phi;
	philo->sim_start = ft_time();
	philo->lunch_time = ft_time();
	pthread_create(&dead, NULL, ft_check_dead, philo);
	while (philo->philo_must_eat)
	{
		if (philo->state->is_dead)
			break ;
		ft_philo_eat(philo);
		if (philo->state->is_dead)
			break ;
		write_message(philo, "is sleeping\n");
		ft_philo_sleep(philo->state->time_sleep);
		if (philo->state->is_dead)
			break ;
		write_message(philo, "is thinking\n");
		philo->philo_must_eat -= 1;
	}
	pthread_join(dead, NULL);
	return (NULL);
}
