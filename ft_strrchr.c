/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:11:04 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 14:29:22 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	int		i;

	a = c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == a)
			return ((char *)&str[i]);
		i--;
	}
	if (!a)
		return ((char *)&str[i]);
	return (0);
}
