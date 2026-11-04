/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:35:46 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 14:39:42 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	char	*s;
	char	a;
	size_t	i;

	s = (char *)str;
	a = (char)c;
	i = 0;
	while (i < len)
	{
		if (a == s[i])
			return (s + i);
		i++;
	}
	return (NULL);
}
