/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:55:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 17:07:05 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_substr.h"

t_test_result	ft_do_test_substr(void *p)
{
	const t_params_substr	*params = (t_params_substr *)p;
	t_test_result			result;

	result.desc = params->desc;
	result.expected = params->expected;
	result.result = ft_substr(params->src, params->start, params->len);
	result.success = (result.result == NULL && result.expected == NULL)
		|| !strcmp(result.expected, result.result);
	return (result);
}

t_test_set_result	ft_tests_substr(void)
{
	const t_test_case_substr	test_cases[] = {
	{ft_do_test_substr, {"Basic substring", "Hello, world!", 0, 5, "Hello",}},
	{ft_do_test_substr, {"Middle substring", "Hello, world!", 7, 5, "world",}},
	{ft_do_test_substr, {"Length exceeds source", "Hello, world!", 10, 50,
		"ld!"}},
	{ft_do_test_substr, {"Start beyond length", "Hello, world!", 100, 5, ""}},
	{ft_do_test_substr, {"Zero length", "Hello, world!", 5, 0, ""}},
	{ft_do_test_substr, {"Empty string", "", 0, 5, ""}},
	{ft_do_test_substr, {"NULL input", NULL, 0, 5, NULL, }},
	{ft_do_test_substr, {"Partial copy", "Hello, world!", 1, 3, "ell",}},
	{ft_do_test_substr, {"Edge boundary", "abcd", 2, 1, "c",}},
	};
	const int					total = sizeof(test_cases)
		/ sizeof(t_test_case_substr);
	uint16_t					i;
	t_test						*tests;
	t_test_set_result			result;

	tests = malloc(total * sizeof(t_test));
	i = 0;
	while (i < total)
	{
		tests[i].f = test_cases[i].f;
		tests[i].params = (void *) &test_cases[i].params;
		i++;
	}
	result = ft_run_tests("ft_substr", tests, total);
	i = 0;
	free(tests);
	return (result);
}
