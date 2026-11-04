/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:30:18 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 14:32:19 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < size)
		i++;
	if (i == size)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char)s2[i]);
}
