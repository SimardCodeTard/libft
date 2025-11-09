/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:12:33 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 21:26:14 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_splitted(char **splitted, int k)
{
	while (k >= 0)
	{
		free(splitted[k]);
		k--;
	}
	free(splitted);
	return (ft_calloc(1, sizeof(char *)));
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char			**splitted;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (calloc(1, sizeof(char *)));
	splitted = calloc(count_words(s, c) + 1, sizeof(char *));
	if (!splitted)
		return (calloc(1, sizeof(char *)));
	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[j] && s[j] != c)
			j++;
		splitted[k++] = ft_substr(s, i, j - i + 1);
		if (!splitted[k - 1])
			return (free_splitted(splitted, (int) k - 2));
		i = j;
	}
	return (splitted);
}
