/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:45:00 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 21:23:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	lst_has_cycle(t_list *lst)
{
	const t_list	*the_chosen_one = lst;

	if (!lst)
		return (false);
	while (lst->next)
	{
		lst = lst->next;
		if (lst == the_chosen_one)
			return (true);
	}
	return (false);
}

static void	*ft_clear_return(t_list *n_lst, void (*del)(void *))
{
	ft_lstclear(&n_lst, del);
	return (NULL);
}

static t_list	*ft_lstmap_cyclic(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	const t_list	*the_chosen_one = lst;
	t_list			*new_list;
	t_list			*current;
	bool			is_first_iteration;

	new_list = ft_lstnew(NULL);
	if (!lst ||!new_list)
		return (ft_clear_return(new_list, del));
	current = new_list;
	is_first_iteration = true;
	while (lst != the_chosen_one || is_first_iteration)
	{
		current->content = f(lst->content);
		if (lst != the_chosen_one || is_first_iteration)
		{
			current->next = ft_lstnew(NULL);
			if (!current->next)
				return (ft_clear_return(new_list, del));
		}
		current = current->next;
		lst = lst->next;
		is_first_iteration = false;
	}
	return (new_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	if (lst_has_cycle(lst))
		return (ft_lstmap_cyclic(lst, f, del));
	if (!lst)
		return (NULL);
	new_list = ft_lstnew(NULL);
	if (!new_list)
		return (ft_clear_return(new_list, del));
	current = new_list;
	while (lst)
	{
		current->content = f(lst->content);
		if (lst->next)
		{
			current->next = ft_lstnew(NULL);
			if (!current->next)
				return (ft_clear_return(new_list, del));
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_list);
}
