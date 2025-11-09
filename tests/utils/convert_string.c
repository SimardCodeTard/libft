/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:04:50 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 20:14:45 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static char	*convert_unprintable_char( char c)
{
	char	*str;

	str = malloc(5);
	if (!str)
		return (NULL);
	switch (c)
	{
		case 7:
			sprintf(str, "%s", "\\a");
		break ;
		case 8:
			sprintf(str, "%s", "\\b");
		break ;
		case 9:
			sprintf(str, "%s", "\\t");
		break ;
		case 10:
			sprintf(str, "%s", "\\n");
		break ;
		case 11:
			sprintf(str, "%s", "\\v");
		break ;
		case 12:
			sprintf(str, "%s", "\\f");
		break ;
		case 13:
			sprintf(str, "%s", "\\r");
		break ;
		default :
			sprintf(str, c < 10 ? "\\x0%d" : "\\x%d", c);
		break ;
	}
	return (str);
}

static char	*replace_unprintable_char(char *s, char c, size_t *i)
{
	char	*prev_s;
	char	*converted_char_buffer;

	converted_char_buffer = convert_unprintable_char(c);
	prev_s = s;
	s = ft_strjoin(s, (char *) converted_char_buffer);
	free(prev_s);
	if (!s)
		return (calloc(1, sizeof(1)));
	*i += strlen(converted_char_buffer);
	free(converted_char_buffer);
	return (s);
}

static size_t	get_converted_len(char *s)
{
	size_t	len;
	char	*converted_char;

	len = 0;
	while (*s)
	{
		if (isprint(*s))
			len += 1;
		else
		{
			converted_char = convert_unprintable_char(*s);
			len += strlen(converted_char);
			free(converted_char);
		}
		s++;
	}
	return (len);
}

char	*convert_string(char *s)
{
	char	*conv_s;
	size_t	i;

	if (!s)
		return (calloc(1, sizeof(char)));
	i = 0;
	conv_s = calloc(get_converted_len(s), sizeof(char));
	if (!conv_s)
		return (calloc(1, sizeof(char)));
	while (*s)
	{
		if (isprint(*s))
			conv_s[i++] = *s;
		else
			conv_s = replace_unprintable_char(conv_s, *s, &i);
		s++;
	}
	return (conv_s);
}
