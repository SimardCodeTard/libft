/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:12:40 by smenard           #+#    #+#             */
/*   Updated: 2025/11/06 16:25:46 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substr_found_len(const char *from, const char *sub)
{
	size_t	count;

	count = 0;
	while (from[count] && from[count] == sub[count])
		count++;
	return (count);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	const size_t	little_len = ft_strlen(little);

	if (!little[0])
		return ((char *) big);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (ft_substr_found_len(&(big[i]), little) == little_len)
			return ((char *) &(big[i]));
		i++;
	}
	return (NULL);
}
