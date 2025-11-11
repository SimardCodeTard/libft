/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:34:52 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:59:35 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_itoa.h"

t_test_result	ft_do_test_itoa(void *p)
{
	t_params_itoa	*params = (t_params_itoa *) p;
	t_test_result	res;
	char			*result;

	result = ft_itoa(params->n);
	res.expected = params->expected;
	res.desc = params->desc;
	res.result = result;
	res.success = !strcmp(result, params->expected);
	return (res);
}

t_test_set_result	ft_tests_itoa(void)
{
	const t_test_case_itoa	test_cases[] = {
	{ft_do_test_itoa, {"Simple number (funny)", 69, "69"}},
	{ft_do_test_itoa, {"Simple negative number (funny)", -69, "-69"}},
	{ft_do_test_itoa, {"Zero", 0, "0"}},
	{ft_do_test_itoa, {"Int max", INT_MAX, "2147483647"}},
	{ft_do_test_itoa, {"Int min", INT_MIN, "-2147483648"}},
	{ft_do_test_itoa, {"Nine", 9, "9"}},
	{ft_do_test_itoa, {"Minus nine", -9, "-9"}},
	};
	const int				total = sizeof(test_cases)
		/ sizeof(t_test_case_itoa);
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
	result = ft_run_tests("ft_itoa", tests, total);
	free(tests);
	return (result);
}
