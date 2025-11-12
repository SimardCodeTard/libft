/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:03:39 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 20:16:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*lst_tostring_char(t_list *lst)
{
	t_list		*curr;
	char		*to_string;
	char		*prev_to_string;
	char		buff[2];

	if (!lst)
		return (ft_strdup("{ }"));
	to_string = ft_strdup("{ ");
	curr = lst;
	while (curr)
	{
		prev_to_string = to_string;
		buff[0] = *(char *)(curr->content);
		buff[1] = '\0';
		to_string = ft_strjoin(to_string, buff);
		free(prev_to_string);
		if (curr->next)
		{
			prev_to_string = to_string;
			to_string = ft_strjoin(to_string, " -> ");
			free(prev_to_string);
		}
		curr = curr->next;
	}
	prev_to_string = to_string;
	to_string = ft_strjoin(to_string, " }");
	free(prev_to_string);
	return (to_string);
}
char	*lst_tostring_str(t_list *lst)
{
	t_list		*curr;
	char		*to_string;
	char		*prev_to_string;

	if (!lst)
		return (ft_strdup("{ }"));
	to_string = ft_strdup("{ ");
	curr = lst;
	while (curr)
	{
		prev_to_string = to_string;
		if (curr->content)
			to_string = ft_strjoin(to_string, (char *)(curr->content));
		else
			to_string = ft_strjoin(to_string, "(null)");
		free(prev_to_string);
		prev_to_string = to_string;
		to_string = ft_strjoin(to_string, " -> ");
		free(prev_to_string);
		curr = curr->next;
	}
	prev_to_string = to_string;
	to_string = ft_strjoin(to_string, "(null) }");
	free(prev_to_string);
	return (to_string);
}


char	*lst_tostring_str_cyclic(t_list *lst)
{
	t_list	*curr;
	t_list	*start;
	char	*to_string;
	char	*prev_to_string;

	if (!lst)
		return (ft_strdup("{ }"));
	to_string = ft_strdup("{ ");
	curr = lst;
	start = lst;
	while (curr)
	{
		prev_to_string = to_string;
		if (curr->content)
			to_string = ft_strjoin(to_string, (char *)(curr->content));
		else
			to_string = ft_strjoin(to_string, "(null)");
		free(prev_to_string);
		if (curr->next == start)
		{
			prev_to_string = to_string;
			to_string = ft_strjoin(to_string, " -> (cycle)");
			free(prev_to_string);
			break ;
		}
		prev_to_string = to_string;
		to_string = ft_strjoin(to_string, " -> ");
		free(prev_to_string);
		curr = curr->next;
	}
	prev_to_string = to_string;
	to_string = ft_strjoin(to_string, " }");
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
	to_string = ft_strjoin(to_string, " }");
	free(prev_to_string);
	return (to_string);
}
