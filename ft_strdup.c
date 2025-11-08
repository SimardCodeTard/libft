/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:43:01 by smenard           #+#    #+#             */
/*   Updated: 2025/11/06 20:11:53 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const size_t	s_len = ft_strlen(s);
	char			*ns;
	size_t			i;

	i = 0;
	ns = malloc(s_len + 1);
	if (!ns)
		return (NULL);
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}
