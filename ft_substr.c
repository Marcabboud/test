/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabboud <maabboud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:57:38 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/04 16:32:50 by maabboud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*string;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len - start)
		len = str_len - start;
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
		return (string);
}
