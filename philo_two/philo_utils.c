/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:52:45 by flavon            #+#    #+#             */
/*   Updated: 2020/11/21 16:59:14 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long int	ft_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	write_message(t_philo *philo, char *str)
{
	char *time_msg;
	char *philo_id;

	sem_wait(philo->state->out);
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
	sem_post(philo->state->out);
}