/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:15:41 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 13:48:57 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	total;
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	total = len_dest + len_src;
	if (size <= 0)
		return (len_src);
	if (size <= len_dest)
		return (len_src + size);
	i = 0;
	while (src && (len_dest + i) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (total);
}
