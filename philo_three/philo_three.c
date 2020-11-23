/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:35:29 by flavon            #+#    #+#             */
/*   Updated: 2020/11/24 02:45:02 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_philo_sleep(int time)
{
	long start_time;

	start_time = ft_time();
	while (ft_time() - start_time < time)
		usleep(1);
}



void	ft_philo_eat(t_philo *philo)
{
	sem_wait(philo->state->waiter);
	sem_wait(philo->state->forks);
	sem_wait(philo->state->out);
	write_message(philo, "has taken a fork\n");
	sem_post(philo->state->out);
	sem_wait(philo->state->forks);
	sem_wait(philo->state->out);
	write_message(philo, "has taken a fork\n");
	sem_post(philo->state->out);
	sem_post(philo->state->waiter);
	sem_wait(philo->state->out);
	write_message(philo, "start eating\n");
	sem_post(philo->state->out);
	sem_wait(philo->state->time);
	philo->lunch_time = ft_time();
	sem_post(philo->state->time);
	ft_philo_sleep(philo->state->time_eat);
	sem_post(philo->state->forks);
	sem_post(philo->state->forks);

}

void	*ft_check_dead(void *phi)
{
	t_philo *philo;

	philo = (t_philo *)phi;
	while(1)
	{
		sem_wait(philo->state->time);
		if (ft_time() - philo->lunch_time > philo->state->time_die)
			break ;
		sem_post(philo->state->time);
	}
	sem_post(philo->state->time);
	if (!philo->philo_must_eat)
		return (NULL);
	sem_wait(philo->state->out);
	write_message(philo, RED"is dead\n"RESET);
	philo->state->is_dead = 1;
	sem_post(philo->state->philo_died);
	sem_post(philo->state->death);
	return (NULL);
}

void	start_simulation(t_philo *philo)
{
	pthread_t dead;

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
		sem_wait(philo->state->out);
		write_message(philo, "is sleeping\n");
		sem_post(philo->state->out);
		ft_philo_sleep(philo->state->time_sleep);
		if (philo->state->is_dead)
			break ;
		sem_wait(philo->state->out);
		write_message(philo, "is thinking\n");
		sem_post(philo->state->out);
		philo->philo_must_eat -= 1;
	}
	pthread_join(dead, NULL);
}