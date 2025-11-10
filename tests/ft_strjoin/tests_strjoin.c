/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:03:18 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 14:41:56 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strjoin.h"

void	ft_tests_strjoin(void)
{
	const t_test_case_strjoin	tests[] = {
	{"Basic join", "Hello,", " world!", "Hello, world!", false},
	{"Empty s1", "", " world!", " world!", false},
	{"Empty s2", "Hello,", "", "Hello,", false},
	{"Empty s1 and s2", "", "", "", false},
	{"NULL s1", NULL, " world!", " world!", false},
	{"NULL s2", "Hello,", NULL, "Hello,", false},
	{"Both NULL", NULL, NULL, "", false},
	};
	const int					total = sizeof(tests)
		/sizeof(t_test_case_strjoin);
	int							passed;
	int							success;
	char						*result;
	int							i;

	passed = 0;
	i = 0;
	printf("===== ft_strjoin tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		result = ft_strjoin(tests[i].s1, tests[i].s2);
		if (tests[i].allow_null && result == NULL)
			success = 1;
		else if (TEST_STR(tests[i].expected, result))
			success = 1;
		if (success)
		{
			printf(GREEN "[%2d] %-80s -> Success!\n" RESET, i + 1,
				tests[i].desc);
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
