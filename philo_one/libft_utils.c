/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:31:51 by flavon            #+#    #+#             */
/*   Updated: 2020/10/26 14:44:28 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_atoi(const char *src)
{
	long int	result;
	int			negative;

	result = 0;
	while (*src != 0 && ((*src >= 9 && *src <= 13) || *src == 32))
		src++;
	negative = (*src == '-') ? -1 : 1;
	if (*src == '+' || *src == '-')
		src++;
	while (*src != 0 && (*src >= 48 && *src <= 57))
		result = (result * 10) + *src++ - '0';
	return (result * negative);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}