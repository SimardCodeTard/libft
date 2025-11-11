/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:25:38 by simard            #+#    #+#             */
/*   Updated: 2025/11/11 16:32:01 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static t_test_result	ft_run_test(t_test test,
	uint16_t n)
{
	t_test_result	res;

	res = test.f(test.params);
	if (res.success)
	{
		printf(KGRN"[%2d] %s%-70s%s Success !\n" KNRM, n, KNRM, res.desc, KGRN);
	}
	else
	{
		printf(KRED "[%2d] %s%-70s %sFailure !%s\nExpected: %s%s%s, Got: %s%s\n" KNRM,
			n, KNRM, res.desc, KRED, KNRM, KYEL, res.expected, KNRM, KYEL, res.result);
	}
	return (res);
}

t_test_set_result	ft_run_tests(const char *name,
	t_test *tests, unsigned int n)
{
	t_test_set_result	result;
	uint16_t			i;

	result.success_count = 0;
	result.failure_count = 0;
	printf("\n===== Running %s%d%s tests accross for function %s\"%s\"%s =====\n",
		KYEL, n, KNRM, KBLU, name, KNRM);
	i = 0;
	while (i < n)
	{
		if (ft_run_test(tests[i], i).success)
			result.success_count++;
		else
			result.failure_count++;
		i++;
	}
	i = 0;
	if (!result.failure_count)
		printf(KGRN "All tests succeded !✅\n" KNRM);
	else
	{
		printf(KRED"%d/%d test(s) failed !❌\n" KNRM,
			result.failure_count,
			result.failure_count + result.success_count);
	}
	result.name = name;
	return (result);
}
