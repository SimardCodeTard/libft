/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:03:18 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:22:33 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strjoin.h"

t_test_result	ft_do_test_strjoin(void *p)
{
	const t_params_strjoin	*params = (t_params_strjoin *)p;
	t_test_result			test_result;

	test_result.desc = params->desc;
	test_result.result = ft_strjoin(params->s1, params->s2);
	test_result.expected = params->expected;
	test_result.success = !strcmp(params->expected, test_result.result);
	return (test_result);
}

t_test_set_result	ft_tests_strjoin(void)
{
	const t_test_case_strjoin	test_cases[] = {
	{ft_do_test_strjoin, {"Basic join", "Hello,", " world!", "Hello, world!"}},
	{ft_do_test_strjoin, {"Empty s1", "", " world!", " world!"}},
	{ft_do_test_strjoin, {"Empty s2", "Hello,", "", "Hello,"}},
	{ft_do_test_strjoin, {"Empty s1 and s2", "", "", ""}},
	{ft_do_test_strjoin, {"NULL s1", NULL, " world!", " world!"}},
	{ft_do_test_strjoin, {"NULL s2", "Hello,", NULL, "Hello,"}},
	{ft_do_test_strjoin, {"Both NULL", NULL, NULL, ""}},
	};
	const int					total = sizeof(test_cases)
		/sizeof(t_test_case_strjoin);
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
	result = ft_run_tests("ft_strjoin", tests, total);
	i = 0;
	free(tests);
	return (result);
}
