/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:46:09 by smenard           #+#    #+#             */
/*   Updated: 2025/11/13 20:42:44 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s_joined;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	s_joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s_joined)
		return (NULL);
	if (s1)
		ft_memcpy(s_joined, s1, s1_len);
	if (s2)
		ft_memcpy(s_joined + s1_len, s2, s2_len);
	s_joined[s1_len + s2_len] = '\0';
	return (s_joined);
}
