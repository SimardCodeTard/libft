/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strscmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:29:39 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 21:52:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	strscmp(const char **ss1, const char **ss2)
{
	int	i;
	int	j;
	int	cmp_res;

	i = 0;
	j = 0;
	while (ss1[i] || ss2[i])
	{
		cmp_res = strcmp(ss1[i], ss2[i]);
		if (cmp_res)
			return (cmp_res);
		i++;
	}
	if (ss1[i] || ss2[i])
		return (strcmp(ss1[i], ss2[i]));
	return (0);
}
