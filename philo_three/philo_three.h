/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:14:15 by flavon            #+#    #+#             */
/*   Updated: 2020/11/27 02:15:13 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
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
	sem_t			*forks;
	sem_t			*time;
	sem_t			*out;
	sem_t			*death;
	sem_t			*waiter;
	sem_t			*philo_died;
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

void				start_simulation(t_philo *phi);

/*
**				SIMULATION_UTILS
*/

int					ft_time(void);
void				take_fork(t_philo *philo, int left, int right, int flag);
void				write_message(t_philo *philo, char *str);

#endif
