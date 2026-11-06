/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:37:26 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/05 18:33:24 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;
	if (size != 0 && n > (size_t)-1 / size)
		return (NULL);
	if (n == 0 || size == 0)
		res = malloc(1);
	else
		res = malloc(n * size);
	if (!res)
		return (NULL);
	ft_bzero(res, n * size);
	return (res);
}
