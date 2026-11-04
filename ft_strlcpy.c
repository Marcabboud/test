/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:07:40 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 13:39:37 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *str, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	while (str[i] && i < size - 1)
	{
		dest[i] = str[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (j);
}
