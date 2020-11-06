/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:13:40 by flavon            #+#    #+#             */
/*   Updated: 2020/11/06 19:39:54 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int ft_argv_check(char **argv, int argc, t_data *data)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	if (argc < 5 || argc > 6)
	{
		ft_putstr("Wrong count arguments\n");
		return (0);
	}
	if ((data->count_philo = ft_atoi(argv[1])) < 2 ||
		!(data->time_die = (unsigned int)ft_atoi(argv[2])) ||
		!(data->time_eat = (unsigned int)ft_atoi(argv[3])) ||
		!(data->time_sleep = (unsigned int)ft_atoi(argv[4])) ||
		!(data->philo_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1))
		return (0);
	data->philo = mutex;
	data->count_forks = data->count_philo;
	return (1);
}

int ft_philo_start(t_data *data)
{
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (!ft_argv_check(argv, argc, &data))
	{
		ft_putstr("Invalid arguments\n");
		return (1);
	}
	if (ft_philo_start(&data))
	{
		return (1);
	}
	return (0);
}