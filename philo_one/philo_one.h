/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:14:15 by flavon            #+#    #+#             */
/*   Updated: 2020/11/06 19:27:42 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>


typedef struct			s_data
{
	int					count_philo;
	int					count_forks;
	unsigned int		time_die;
	unsigned int		time_eat;
	unsigned int		time_sleep;
	int 				philo_must_eat;
	pthread_mutex_t		philo;
	pthread_mutex_t		forks;
}						t_data;

typedef struct			s_philo
{
	int					id;
	int					lunch_time;
	t_data				*data;
}						t_philo;


int						ft_atoi(const char *src);
void					ft_putstr(char *str);

#endif