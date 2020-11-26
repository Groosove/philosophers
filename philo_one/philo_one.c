/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:35:29 by flavon            #+#    #+#             */
/*   Updated: 2020/11/26 19:00:38 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_philo_sleep(int time)
{
	int start_time;

	start_time = ft_time();
	while (ft_time() - start_time < time)
		usleep(10);
}

void	ft_philo_eat(t_philo *philo)
{
	int r_fork;
	int l_fork;

	r_fork = (philo->id + 1) % philo->state->count_philo;
	l_fork = philo->id;
	if (philo->id % 2 == 0)
		take_fork(philo, l_fork, r_fork);
	else
		take_fork(philo, r_fork, l_fork);
	write_message(philo, "start eating\n");
	pthread_mutex_lock(&philo->state->philo_time);
	philo->lunch_time = ft_time();
	pthread_mutex_unlock(&philo->state->philo_time);
	ft_philo_sleep(philo->state->time_eat);
	pthread_mutex_unlock(&philo->state->forks[r_fork]);
	pthread_mutex_unlock(&philo->state->forks[l_fork]);
}

void	*ft_check_dead(void *phi)
{
	t_philo *philo;

	philo = (t_philo *)phi;
	while (1)
	{
		pthread_mutex_lock(&philo->state->philo_time);
		if (ft_time() - philo->lunch_time > philo->state->time_die)
			break ;
		pthread_mutex_unlock(&philo->state->philo_time);
		usleep(10);
	}
	pthread_mutex_unlock(&philo->state->philo_time);
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
