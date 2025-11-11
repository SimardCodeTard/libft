/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strmapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:03:50 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:30:54 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strmapi.h"

t_test_result	ft_do_test_strmapi(void *p)
{
	const t_params_strmapi	*params = (t_params_strmapi	*) p;
	t_test_result			test_result;

	test_result.desc = params->desc;
	test_result.result = ft_strmapi(params->s, params->f);
	test_result.expected = params->expected;
	test_result.success = !strcmp(params->expected, test_result.result);
	return (test_result);
}

char	f_toupper(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

char	f_tolower(unsigned int i, char c)
{
	(void) i;
	return (ft_tolower(c));
}

char	f_addindex(unsigned int i, char c)
{
	return (c + i);
}

t_test_set_result	ft_tests_strmapi(void)
{
	const t_test_case_strmapi	test_cases[] = {
	{ft_do_test_strmapi, {"To upper", "abcdefghijklmnopqrstuvwxyz", f_toupper,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}},
	{ft_do_test_strmapi, {"To lower", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_tolower,
		"abcdefghijklmnopqrstuvwxyz"}},
	{ft_do_test_strmapi, {"Add index", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_addindex,
		"ACEGIKMOQSUWY[]_acegikmoqs"}},
	};
	const int					total = sizeof(test_cases)
		/sizeof(t_test_case_strmapi);
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
	result = ft_run_tests("ft_strmapi", tests, total);
	i = 0;
	free(tests);
	return (result);
}
