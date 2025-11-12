/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:12:28 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 19:52:50 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static int	ft_strcmp_safe(const char *s1, const char *s2)
{
	if ((s1 == NULL || s2 == NULL) && s1 != s2)
		return (1);
	return (strcmp(s1, s2));
}
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

	while (l1 && l2 && l1->next != the_chosen_one_1 && l2->next != the_chosen_one_2
		&& !ft_strcmp_safe((char *) l1->content, (char *) l2->content))
	{
		printf("[%u] l1 = %p, l2 = %p, l1->content = %s, l2->content = %s\n",
			(unsigned) t_i,
			(void *) l1,
			(void *) l2,
			l1->content ? (char *) l1->content : "(null)",
			l2->content ? (char *) l2->content : "(null)");
		l1 = l1->next;
		l2 = l2->next;
		t_i++;
	}
	printf("[%u] l1 = %p, l2 = %p, l1->content = %s, l2->content = %s\n",
		(unsigned) t_i,
		(void *) l1,
		(void *) l2,
		(l1 && l1->content) ? (char *) l1->content : "(null)",
		(l2 && l2->content) ? (char *) l2->content : "(null)");
	if (!l1 || !l2)
		return (l1 == l2);
	return (!ft_strcmp_safe((char *) l1->content, (char *) l2->content));
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
