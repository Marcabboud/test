/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:15:41 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/05 18:44:05 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest,const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	len_dest = 0;
	len_src = ft_strlen(src);
	while (len_dest < size && dest[len_dest])
		len_dest++;
	if (len_dest == size)
		return (size + len_src);
	i = 0;
	while (src[i] && (len_dest + i) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
