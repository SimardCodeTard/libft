/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:19 by smenard           #+#    #+#             */
/*   Updated: 2025/11/05 18:37:58 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;
	size_t	i;

	if (((long) src) < ((long) dest))
	{
		i = n - 1;
		while (i >= )
		{
			src[i] = dest[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			src[i] = dest[i];
			i++;
		}
	}
	return (dest);
}
