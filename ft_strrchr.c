/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:34:16 by smenard           #+#    #+#             */
/*   Updated: 2025/11/07 13:28:42 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = NULL;
	while (*s)
	{
		if (*s == (unsigned char) c)
			found = (char *) s;
		s++;
	}
	if (!((unsigned char) c))
		return ((char*) s);
	return (found);
}
