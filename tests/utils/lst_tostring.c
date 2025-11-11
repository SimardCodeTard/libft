/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:03:39 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 18:40:03 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*lst_tostring_char(t_list *lst)
{
	t_list		*curr;
	char		*to_string;
	char		*prev_to_string;
	char		buff[2];

	to_string = NULL;
	curr = lst;
	ft_strjoin(to_string, "{ ");
	while (curr->next)
	{
		prev_to_string = to_string;
		buff[0] = *(char *) (curr->content);
		buff[1] = '\0';
		ft_strjoin(to_string, buff);
		free(prev_to_string);
		if (curr->next)
		{
			prev_to_string = to_string;
			ft_strjoin(to_string, " -> ");
			free(prev_to_string);
		}
		curr = curr->next;
	}
	prev_to_string = to_string;
	ft_strjoin(to_string, " }");
	free(prev_to_string);
	return (to_string);
}

char	*lst_tostring_str(t_list *lst)
{
	t_list		*curr;
	char		*to_string;
	char		*prev_to_string;

	to_string = NULL;
	curr = lst;
	ft_strjoin(to_string, "{ ");
	while (curr->next)
	{
		prev_to_string = to_string;
		ft_strjoin(to_string, *(char **)(curr->content));
		free(prev_to_string);
		if (curr->next)
		{
			prev_to_string = to_string;
			ft_strjoin(to_string, " -> ");
			free(prev_to_string);
		}
		curr = curr->next;
	}
	prev_to_string = to_string;
	ft_strjoin(to_string, " }");
	free(prev_to_string);
	return (to_string);
}

char	*lst_tostring_int(t_list *lst)
{
	t_list		*curr;
	char		*to_string;
	char		*prev_to_string;

	to_string = NULL;
	curr = lst;
	ft_strjoin(to_string, "{ ");
	while (curr->next)
	{
		prev_to_string = to_string;
		ft_strjoin(to_string, ft_itoa(*(int *)curr->content));
		free(prev_to_string);
		if (curr->next)
		{
			prev_to_string = to_string;
			ft_strjoin(to_string, " -> ");
			free(prev_to_string);
		}
		curr = curr->next;
	}
	prev_to_string = to_string;
	ft_strjoin(to_string, " }");
	free(prev_to_string);
	return (to_string);
}
