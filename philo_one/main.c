/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:13:40 by flavon            #+#    #+#             */
/*   Updated: 2020/11/05 03:30:48 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_argv_check(char **argv, int argc, t_philo *philo)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr("Wrong count arguments\n");
		return (0);
	}
	if ((philo->count_philo = ft_atoi(argv[1])) < 2 ||
		!(philo->time_die = ft_atoi(argv[2])) ||
		!(philo->time_eat = ft_atoi(argv[3])) ||
		!(philo->time_sleep = ft_atoi(argv[4])) ||
		!(philo->philo_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1))
		return (0);
	return (1);
}

void	ft_philo_start(char **argv)
{
	(void)argv;
}

int		main(int argc, char **argv)
{
	t_philo					philo;
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	
	if (!ft_argv_check(argv, argc, &philo))
	{
		ft_putstr("Invalid arguments\n");
		return (0);
	}
	return (0);
}