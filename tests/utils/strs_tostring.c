/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_tostring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:07 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 13:47:31 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*strs_tostring(const char **strs)
{
	size_t	i;
	char	*to_string;
	char	*prev_to_string;

	to_string = NULL;
	i = 0;
	to_string = ft_strjoin(to_string, "{ ");
	while (strs[i])
	{
		prev_to_string = to_string;
		to_string = ft_strjoin(to_string, "\"");
		free(prev_to_string);
		prev_to_string = to_string;
		to_string = ft_strjoin(to_string, strs[i]);
		free(prev_to_string);
		prev_to_string = to_string;
		to_string = ft_strjoin(to_string, ", ");
		free(prev_to_string);
		i++;
	}
	prev_to_string = to_string;
	to_string = ft_strjoin(to_string, "NULL }");
	free(prev_to_string);
	return (to_string);
}
