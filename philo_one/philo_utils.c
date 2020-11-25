/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:52:45 by flavon            #+#    #+#             */
/*   Updated: 2020/11/25 23:06:35 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long int	ft_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void		take_fork(t_philo *philo, int left_fork, int right_fork, int flag)
{
	if (flag)
	{
		pthread_mutex_lock(&philo->state->forks[left_fork]);
		write_message(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->state->forks[right_fork]);
		write_message(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_unlock(&philo->state->forks[right_fork]);
		pthread_mutex_unlock(&philo->state->forks[left_fork]);
	}
}

void		write_message(t_philo *philo, char *str)
{
	char *time_msg;
	char *philo_id;

	pthread_mutex_lock(&philo->state->out);
	time_msg = ft_itoa(ft_time() - philo->sim_start);
	philo_id = ft_itoa(philo->id + 1);
	if (!philo->state->is_dead)
	{
		write(1, time_msg, ft_strlen(time_msg));
		write(1, " ", 1);
		write(1, philo_id, ft_strlen(philo_id));
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
	}
	free(time_msg);
	free(philo_id);
	pthread_mutex_unlock(&philo->state->out);
}
