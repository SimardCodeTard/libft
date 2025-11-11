/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:56:39 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 18:42:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_lstnew.h"

t_test_result	ft_do_test_lstnew(void *p)
{
	t_params_lstnew	*params;
	t_test_result	test_result;
	t_list			*result;

	params = (t_params_lstnew *)p;
	result = ft_lstnew(params->content);
	test_result.desc = params->desc;
	test_result.expected = params->expected;
	if (params->content == NULL)
		test_result.result = NULL;
	if (params->content_type == FT_CTYPE_CHAR)
		test_result.result = lst_tostring_char(result);
	else if (params->content_type == FT_CTYPE_STRING)
		test_result.result = lst_tostring_str(result);
	else
		test_result.result = lst_tostring_int(result);
	if (params->content == NULL)
		test_result.success = result->content == params->expected;
	else
		test_result.success = !memcmp(params->expected, result->content, sizeof(&result->content));
	test_result.success &= !result->next;
	return (test_result);
}

t_test_set_result	ft_tests_lstnew(void)
{
	int							funny = 69;
	int							negative_funny = -69;
	char						*funny_string = "69";
	char						c = 'p';
	const t_test_case_lstnew	test_cases[] = {
		{ft_do_test_lstnew, {"Simple number (funny)", &funny, &funny, FT_CTYPE_INT}},
		{ft_do_test_lstnew, {"Simple number (funny) (negative)",&negative_funny, &negative_funny, FT_CTYPE_INT}},
		{ft_do_test_lstnew, {"Simple string (hillarious)", &funny_string, &funny_string, FT_CTYPE_INT}},
		{ft_do_test_lstnew, {"NULL", NULL, NULL, FT_CTYPE_INT}},
		{ft_do_test_lstnew, {"Character", &c, &c, FT_CTYPE_INT}},
	};
	const int				total = sizeof(test_cases)
		/ sizeof(t_test_case_lstnew);
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
	result = ft_run_tests("ft_lstnew", tests, total);
	free(tests);
	return (result);
}
