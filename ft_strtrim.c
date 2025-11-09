/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:00:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 17:25:54 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_trimmed_len(const char *s1, const char *set)
{
	size_t	count;

	if (!s1)
		return (0);
	count = 0;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
				count++;
		s1++;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;
	char	*s_trimmed;

	len = get_trimmed_len(s1, set);
	if (len == 0)
		return (ft_calloc(1, sizeof(char)));
	s_trimmed = malloc(len * sizeof(char));
	if (!s_trimmed)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, *s1))
			s_trimmed[i] = s1[i];
		i++;
	}
	s_trimmed[i] = 0;
	return (s_trimmed);
}
