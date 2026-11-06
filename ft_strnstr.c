/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:43:18 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 14:47:59 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (i + j < len && str[i + j]
			&& str[i + j] == to_find[j] && to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
