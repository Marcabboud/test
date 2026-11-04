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
	int	count;
	int	start;
	int	end;

	if (to_find[0] == '\0')
		return ((char *)str);
	count = 0;
	while (str[count] && len > 0)
	{
		if (len < ft_strlen(to_find))
			return (NULL);
		start = 0;
		end = count;
		while (str[end] == to_find[start] && str[end] && to_find[start])
		{
			start++;
			end++;
		}
		if (to_find[start] == '\0')
			return ((char *)str + count);
		len--;
		count++;
	}
	return (NULL);
}
