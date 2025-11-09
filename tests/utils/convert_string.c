/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:04:50 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 22:16:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static char	*convert_unprintable_char(char c)
{
	char	*special_unprintable_chars[14];
	char	*str;

	special_unprintable_chars['\a'] = "\\a";
	special_unprintable_chars['\b'] = "\\b";
	special_unprintable_chars['\t'] = "\\t";
	special_unprintable_chars['\n'] = "\\n";
	special_unprintable_chars['\v'] = "\\v";
	special_unprintable_chars['\f'] = "\\f";
	special_unprintable_chars['\r'] = "\\r";
	str = malloc(5);
	if (!str)
		return (NULL);
	if (c >= '\a' && c <= '\r')
		sprintf(str, "%s", special_unprintable_chars[(int) c]);
	else if (c < 10)
		sprintf(str, "\\x0%d", c);
	else
		sprintf(str, "\\x%d", c);
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
