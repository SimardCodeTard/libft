/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:34:02 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 17:03:31 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_split.h"

t_test_result	ft_do_test_split(void *p)
{
	const t_params_split	*params = (t_params_split *) p;
	t_test_result			res;
	char					**result;

	result = ft_split(params->s, params->c);
	res.expected = strs_tostring(params->expected);
	res.desc = (char *) params->desc;
	res.result = strs_tostring((const char **) result);
	res.success = !strscmp((const char **) result, params->expected);
	return (res);
}

t_test_set_result	ft_tests_split(void)
{
	static const char		*expected_no_split[] = {"Hello, world!", NULL};
	static const char		*expected_split_2_words[]
		= {"Hello", "world!", NULL};
	static const char		*expected_split_3_words[]
		= {"Hello", "world!", "Hi, mom!", NULL};
	static const char		*expected_split_0_words[] = {NULL};
	static const char		*expected_split_full_sep[] = {NULL};
	const t_test_case_split	test_cases[] = {
	{ft_do_test_split, {"No split", "Hello, world!", ';', expected_no_split}},
	{ft_do_test_split, {"Basic split", "Hello;world!", ';',
		expected_split_2_words}},
	{ft_do_test_split, {"Split with surrounding separators", ";Hello, world!;",
		';', expected_no_split}},
	{ft_do_test_split, {"Split with surrounding separators and multiple words",
		";Hello;world!;", ';', expected_split_2_words}},
	{ft_do_test_split, {
		"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words}},
	{ft_do_test_split, {
		"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words}},
	{ft_do_test_split, {
		"Split with multiple surrounding separators and multiple words\
(uneven)",
		";;;Hello;world!;Hi, mom!;;", ';', expected_split_3_words}},
	{ft_do_test_split, {"Split with empty string", "", ';',
		expected_split_0_words}},
	{ft_do_test_split, {"Split with NULL", NULL, ';', expected_split_0_words}},
	{ft_do_test_split, {"Split with only sep", ";;;;;;;;;;", ';',
		expected_split_full_sep}},
	};
	const int				total = sizeof(test_cases)
		/ sizeof(t_test_case_split);
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
	result = ft_run_tests("ft_split", tests, total);
	free(tests);
	return (result);
}
