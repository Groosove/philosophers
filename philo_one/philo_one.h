/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:14:15 by flavon            #+#    #+#             */
/*   Updated: 2020/10/20 13:02:31 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>


typedef struct	s_philo
{
	int			count_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			philo_must_eat;
}				t_philo;

int		ft_atoi(const char *src);
void	ft_putstr(char *str);

#endif