/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_striteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:18:51 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:31:30 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_striteri.h"

t_test_result	ft_do_test_striter(void *p)
{
	const t_params_striteri	*params = (t_params_striteri *) p;
	t_test_result			test_res;

	ft_striteri(params->s, params->f);
	test_res.desc = params->desc;
	test_res.result = params->s;
	test_res.expected = params->expected;
	test_res.success = !strcmp(params->s, params->expected);
	return (test_res);
}

void	f_toupper_iteri(unsigned int i, char *c)
{
	(void) i;
	*c = ft_toupper(*c);
}

void	f_tolower_iteri(unsigned int i, char *c)
{
	(void) i;
	*c = ft_tolower(*c);
}

void	f_addindex_iteri(unsigned int i, char *c)
{
	*c += i;
}

t_test_set_result	ft_tests_striteri(void)
{
	const t_test_case_striteri	test_cases[] = {
	{ft_do_test_striter, {"To upper", memcpy(calloc(27, sizeof(char)),
		"abcdefghijklmnopqrstuvwxyz", 26), f_toupper_iteri,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}},
	{ft_do_test_striter, {"To lower", memcpy(calloc(27, sizeof(char)),
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26), f_tolower_iteri,
		"abcdefghijklmnopqrstuvwxyz"}},
	{ft_do_test_striter, {"Add index", memcpy(calloc(27, sizeof(char)),
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26), f_addindex_iteri,
		"ACEGIKMOQSUWY[]_acegikmoqs"}},
	};
	const int					total = sizeof(test_cases)
		/sizeof(t_test_case_striteri);
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
	result = ft_run_tests("ft_striteri", tests, total);
	i = 0;
	while (i < total)
	{
		free(test_cases[i].params.s);
		i++;
	}
	free(tests);
	return (result);
}
