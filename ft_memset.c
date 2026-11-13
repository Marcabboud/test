/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:50:14 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/02 13:51:39 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*dest, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)dest;
	while (len > 0)
	{
		*tmp = (unsigned char)c;
		len--;
		tmp++;
	}
	return (dest);
}
