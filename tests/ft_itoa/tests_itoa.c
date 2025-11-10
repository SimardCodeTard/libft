/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:34:52 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 14:41:41 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_itoa.h"

void	ft_tests_itoa(void)
{
	const t_test_case_itoa	tests[] = {
	{"Simple number", 69, "69"},
	{"Simple negative number", -69, "-69"},
	{"Zero", 0, "0"},
	{"Int max", 2147483647, "2147483647"},
	{"Int min", -2147483648, "-2147483648"},
	{"Nine", 9, "9"},
	{"Minus nine", -9, "-9"},
	};
	const int				total = sizeof(tests)
		/ sizeof(t_test_case_itoa);
	int						passed;
	int						success;
	char					*result;
	int						i;

	passed = 0;
	i = 0;
	printf("===== ft_itoa tests =====\n\n");
	while (i < total)
	{
		success = 0;
		result = ft_itoa(tests[i].n);
		if (TEST_STR(tests[i].expected, result))
			success = 1;
		if (success)
		{
			printf(GREEN "[%2d] %-80s -> Success!\n"
				RESET, i + 1, tests[i].desc);
			passed++;
		}
		else
		{
			if (!result)
				result = "NULL";
			printf(RED "[%2d] %-80s -> Failure! Got: \"%s\" expected : \"%s\"\n"
				RESET, i + 1, tests[i].desc, result, tests[i].expected);
		}
		SAFE_FREE(result);
		i++;
	}
	printf("\n===== Summary =====\n");
	if (passed == total)
		printf(GREEN "%d/%d tests passed ✅\n" RESET, passed, total);
	else
		printf(RED "%d/%d tests passed ❌\n" RESET, passed, total);
	printf("===================\n\n\n");
}
