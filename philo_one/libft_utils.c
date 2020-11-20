/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:31:51 by flavon            #+#    #+#             */
/*   Updated: 2020/11/20 10:22:19 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_atoi(const char *src)
{
	long int	result;

	result = 0;
	while (*src != 0 && ((*src >= 9 && *src <= 13) || *src == 32))
		src++;
	if (*src == '+' || *src == '-')
		return (0);
	while (*src != 0 && (*src >= 48 && *src <= 57))
		result = (result * 10) + *src++ - '0';
	return (result);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char		*ft_strchr(const char *str, int ch)
{
	char			*src;
	unsigned int	index;

	src = (char *)str;
	index = 0;
	while (src[index] != 0)
		if (src[index++] == ch)
			return (&src[--index]);
	if (src[index] == ch)
		return (&src[index]);
	return (0);
}

long int	ft_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}