/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:14:15 by flavon            #+#    #+#             */
/*   Updated: 2020/11/26 18:29:43 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

typedef struct		s_state
{
	int				count_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				philo_must_eat;
	int				is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	out;
	pthread_mutex_t	philo_time;
}					t_state;

typedef struct		s_philo
{
	long int		sim_start;
	int				id;
	long int		lunch_time;
	int				philo_must_eat;
	t_state			*state;
}					t_philo;

/*
**				LIBFT-UTILS
*/

int					ft_atoi(const char *src);
void				ft_putstr(char *str);
char				*ft_strchr(const char *str, int ch);
char				*ft_itoa(int n);
int					ft_strlen(char *str);

/*
**				GENERAL_FUNCTION
*/

void				*start_simulation(void *phi);

/*
**				SIMULATION_UTILS
*/

int					ft_time(void);
void				take_fork(t_philo *philo, int left, int right);
void				write_message(t_philo *philo, char *str);

#endif
