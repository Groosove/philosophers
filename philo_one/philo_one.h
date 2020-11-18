/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:14:15 by flavon            #+#    #+#             */
/*   Updated: 2020/11/18 02:16:45 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct		s_state
{
	int				count_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	int				philo_must_eat;
	int 			is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	out;
	pthread_mutex_t	time;
}					t_state;

typedef struct		s_philo
{
	int				sim_start;
	int				id;
	long int		lunch_time;
	int				philo_must_eat;
	t_state			*state;
}					t_philo;

/*
**				LIBFT-UTILS
*/

int				ft_atoi(const char *src);
void			ft_putstr(char *str);
char			*ft_strchr(const char *str, int ch);

/*
**				GENERAL_FUNCTION
*/

#endif