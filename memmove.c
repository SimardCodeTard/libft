/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:19 by smenard           #+#    #+#             */
/*   Updated: 2025/11/05 14:27:53 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;
	size_t	i;

	temp = malloc(n);
	if (!temp)
		return (NULL);
	i = 0;
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	free(temp);
	return (dest);
}
