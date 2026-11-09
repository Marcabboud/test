/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:48:09 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/04 15:34:02 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str);

static int	ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
