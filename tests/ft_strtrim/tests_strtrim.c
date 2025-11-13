/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:48:40 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 17:02:18 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strtrim.h"

t_test_result	ft_do_test_strtrim(void *p)
{
	const t_params_strtrim	*params = (t_params_strtrim *) p;
	t_test_result			result;

	result.desc = params->desc;
	result.expected = params->expected;
	result.result = ft_strtrim(params->s1, params->set);
	result.success = !strcmp(result.expected, result.result);
	return (result);
}

t_test_set_result	ft_tests_strtrim(void)
{
	const t_test_case_strtrim	test_cases[] = {
	{ft_do_test_strtrim, {"Trim '\\n' at the end", "Hello, world!\n",
		"\n", "Hello, world!"}},
	{ft_do_test_strtrim, {"Trim '\\n' in the middle", "Hello,\n world!",
		"\n", "Hello,\n world!"}},
	{ft_do_test_strtrim, {"Trim '\\n' in the middle and at the end",
		"Hello,\n world!\n", "\n", "Hello,\n world!"}},
	{ft_do_test_strtrim, {"Trim '\\n' with an already trimmed string",
		"Hello, world!", "\n", "Hello, world!"}},
	{ft_do_test_strtrim, {"Empty s1", "", "\n", ""}},
	{ft_do_test_strtrim, {"Empty set", "Hello, world!", "", "Hello, world!"}},
	{ft_do_test_strtrim, {"Nulbyte in set", "Hello, world!", "\0",
		"Hello, world!"}},
	{ft_do_test_strtrim, {"Random bullshit",
		"\n\n\t\t\rH\tel\t\t\nlo, w\t\to\nrl\rd\r!\n\n\t\r\n",
		"\n\t\r", "H\tel\t\t\nlo, w\t\to\nrl\rd\r!"}},
	{ft_do_test_strtrim, {"NULL s1", NULL, "\n", ""}},
	{ft_do_test_strtrim, {"Fully trimmed", "          ", " ", ""}},
	};
	const int					total = sizeof(test_cases)
		/ sizeof(t_test_case_strtrim);
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
	result = ft_run_tests("ft_strtrim", tests, total);
	i = 0;
	free(tests);
	return (result);
}
