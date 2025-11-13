/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:06:29 by smenard           #+#    #+#             */
/*   Updated: 2025/11/13 13:03:15 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_test_lstmap.h"



t_test_result	ft_do_test_lstmap(void *p)
{
	t_params_lstmap	*params;
	t_test_result	test_result;
	t_list			*new;

	params = (t_params_lstmap *)p;

	new = ft_lstmap(params->lst, params->f, params->del);
	test_result.success = ft_lsteq(new, params->expected);
	if (ft_lst_has_cycle(new))
		test_result.result = lst_tostring_str_cyclic(new);
	else
		test_result.result = lst_tostring_str(new);
	if (ft_lst_has_cycle(params->lst))
		test_result.expected = lst_tostring_str_cyclic(params->lst);
	else
		test_result.expected = lst_tostring_str(params->lst);
	test_result.desc = params->desc;
	return (test_result);
}

static char ft_toupper_test(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

static void	*f(void *s)
{
	return (ft_strmapi((char *) s, ft_toupper_test));
}

static void	del(void *c)
{
	free(c);
}

t_test_set_result	ft_tests_lstmap(void)
{
	t_list *lst;
	t_list *lst_expected;

	lst = ft_lstnew("abcd");
	lst->next = ft_lstnew("efgh");
	lst->next->next = lst;

	lst_expected = ft_lstnew("ABCD");
	lst_expected->next = ft_lstnew("EFGH");
	lst_expected->next->next = lst_expected;

	const t_test_case_lstmap	test_cases[] = {
		{ft_do_test_lstmap, {"Valid cyclic map", lst, f, del, lst_expected}}
	};
	const int				total = sizeof(test_cases)
		/ sizeof(t_test_case_lstmap);
	uint16_t				i;
	t_test					*tests;
	t_test_set_result		result;

	tests = malloc(total * sizeof(t_test));
	i = 0;
	while (i < total)
	{
		tests[i].f = test_cases[i].f;
		tests[i].params = (void *) &test_cases[i].params;
		i++;
	}
	result = ft_run_tests("ft_lstmap", tests, total);
	free(tests);
	return (result);
}
