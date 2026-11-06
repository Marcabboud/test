/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:45:54 by maabboud          #+#    #+#             */
/*   Updated: 2026/11/05 18:43:48 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_error(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copyword(char const *str, int *i, char c)
{
	char	*word;
	int		len;
	int		j;

	len = 0;
	while (str[*i] == c)
		(*i)++;
	j = *i;
	while (str[j] && str[j] != c)
	{
		len++;
		j++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] != c)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (x < words)
	{
		split[x] = ft_copyword(s, &i, c);
		if (!split[x])
		{
			split[x] = NULL;
			return (ft_error(split));
		}
		x++;
	}
	split[x] = 0;
	return (split);
}
