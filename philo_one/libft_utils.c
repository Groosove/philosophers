/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:31:51 by flavon            #+#    #+#             */
/*   Updated: 2020/11/27 02:17:51 by flavon           ###   ########.fr       */
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
	if (*src != 0)
		return (0);
	return (result);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
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

char		*ft_itoa(int n)
{
	int		nbr;
	char	*res;
	int		len;

	len = 1;
	nbr = n;
	while ((nbr /= 10) != 0)
		++len;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len != 0)
	{
		res[len - 1] = "0123456789abcdef"[n % 10];
		n /= 10;
		len--;
	}
	return (res);
}
