/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:37:48 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/05 19:40:43 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
		return (ft_substr(s1, 0, 0));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_checker(s1[start], set))
		start++;
	while (end >= start && ft_checker(s1[end], set))
		end--;
	if (end == -1)
		return (ft_substr(s1, start, 0));
	return (ft_substr(s1, start, (end - start + 1)));
}
