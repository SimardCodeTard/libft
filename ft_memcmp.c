/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:42 by smenard           #+#    #+#             */
/*   Updated: 2025/11/06 15:39:16 by smenard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cst_s1 = (unsigned char *) s1;
	const unsigned char	*cst_s2 = (unsigned char *) s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (cst_s1[i] != cst_s2[i])
			return (cst_s1[i] - cst_s2[i]);
		i++;
	}
	return (0);
}
