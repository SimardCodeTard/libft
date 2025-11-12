/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:12:28 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 18:14:11 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

bool	ft_lst_has_cycle(t_list *lst)
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

static bool	ft_lsteq_cyclic(t_list *l1, t_list *l2)
{
	const t_list	*the_chosen_one_1 = l1;
	const t_list	*the_chosen_one_2 = l2;
	uint16_t		t_i = 0;

	while (l1->next != the_chosen_one_1 && l2->next != the_chosen_one_2
		&& ((l1->content != NULL && l2->content != NULL) && !strcmp((char *) l1->content, (char *) l2->content)))
	{
		printf("[%d] l1 = %zu, l2 = %zu, l1->content = %s, l2->content = %s\n",
			t_i,
			(long) (void *) l1,
			(long) (void *) l2,
			(char *) l1->content,
			(char *)l2->content);
		l1 = l1->next;
		l2 = l2->next;
		t_i++;
	printf("PROUTXD\n");
	}
	printf("[%d] l1 = %zu, l2 = %zu, l1->content = %s, l2->content = %s\n",
		t_i,
		(long) (void *) l1,
		(long) (void *) l2,
		(char *) l1->content,
		(char *)l2->content);
	return ((l1->content && l2->content) || !strcmp((char *) l1->content, (char *) l2->content));
}
bool	ft_lsteq(t_list *l1, t_list *l2)
{
	if (ft_lst_has_cycle(l1) || ft_lst_has_cycle(l2))
		return (ft_lsteq_cyclic(l1, l2));
	while (l1 && l2 && !strcmp((char *) l1->content, (char *) l2->content))
	{
		l1 = l1->next;
		l2 = l2->next;
	}
	return (!l1 && !l2);
}
