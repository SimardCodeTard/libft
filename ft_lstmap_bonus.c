/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:45:00 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 16:32:29 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static bool	lst_has_cycle(t_list *lst)
// {
// 	const t_list	*the_chosen_one = lst;

// 	if (!lst)
// 		return (false);
// 	while (lst->next)
// 	{
// 		lst = lst->next;
// 		if (lst == the_chosen_one)
// 			return (true);
// 	}
// 	return (false);
// }

static void	*ft_clear_return(t_list *n_lst,void (*del)(void *), void *content)
{
	ft_lstclear(&n_lst, del);
	del(content);
	return (NULL);
}

// t_list	*ft_lstmap_cyclic(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*the_chosen_one;
// 	t_list	*n_lst;
// 	t_list	*curr;
// 	t_list	*next;

// 	the_chosen_one = lst;
// 	n_lst = malloc(sizeof(t_list));
// 	if (!lst || !f || !n_lst)
// 		return (NULL);
// 	curr = n_lst;
// 	while (lst->next != the_chosen_one)
// 	{
// 		curr->content = f(lst->content);
// 		curr->next = malloc(sizeof(t_list));
// 		if (!curr->next)
// 			return (ft_clear_return(lst, n_lst, del));
// 		curr = curr->next;
// 		del(lst->content);
// 		next = lst->next;
// 		free(lst);
// 		lst = next;
// 	}
// 	return (n_lst);
// }

#include <stdio.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**start;
	t_list	*current;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	start = &current;
	while (lst)
	{
		content = f(lst->content);
		current = ft_lstnew(content);
		if (!current)
			return (ft_clear_return(*start, del, content));
		current = current->next;
		lst = lst->next;
	}
	return (*start);
}

// void	*f(void* c)
// {
// 	return ((void *)strlen(c));
// }

// void	del(void *c)
// {
// 	free(c);
// }

// int	main(void)
// {
// 	t_list	*list = ft_lstnew("hello!");
// 	free(ft_lstmap(list, f, del));
// 	free(list);
// }
