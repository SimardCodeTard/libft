/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strscmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:29:39 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 17:14:39 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	strscmp(const char **ss1, const char **ss2)
{
	int	i;
	int	cmp_res;

	i = 0;
	if ((ss1[i] && !ss2[i]) || (!ss1[i] && ss2[i]))
		return (ss1[i] - ss2[i]);
	while ((ss1[i] && ss2[i]))
	{
		cmp_res = strcmp(ss1[i], ss2[i]);
		if (cmp_res)
			return (cmp_res);
		i++;
	}
	if ((ss1[i] || ss2[i]))
		return (ss1[i] - ss2[i]);
	return (0);
}
