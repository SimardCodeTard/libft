/* ************************************************************************** */
/*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*/
/*\t\t\t\t\t\t\t\t\t\t\t\t\t\t:::\t  ::::::::   */
/*   ft_substr.c\t\t\t\t\t\t\t\t\t\t:+:\t  :+:\t:+:   */
/*\t\t\t\t\t\t\t\t\t\t\t\t\t+:+ +:+\t\t +:+\t */
/*   By: smenard <smenard@student.42.fr>\t\t\t+#+  +:+\t   +#+\t\t*/
/*\t\t\t\t\t\t\t\t\t\t\t\t+#+#+#+#+#+   +#+\t\t   */
/*   Created: 2025/11/09 14:06:39 by smenard\t\t   #+#\t#+#\t\t\t */
/*   Updated: 2025/11/09 14:45:32 by smenard\t\t  ###   ########.fr\t   */
/*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		subs = malloc(sizeof(char));
		subs[0] = '\0';
		return (subs);
	}
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
