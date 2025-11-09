/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:55:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 15:07:39 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"
#include "macros/colors.h"
#include "macros/test_helpers.h"
#include "struct/test_case.h"

int	main(void)
{
	const t_test_case	tests[] = {
	{"Basic substring", "Hello, world!", 0, 5, "Hello", 0},
	{"Middle substring", "Hello, world!", 7, 5, "world", 0},
	{"Length exceeds source", "Hello, world!", 10, 50, "ld!", 1},
	{"Start beyond length", "Hello, world!", 100, 5, "", 1},
	{"Zero length", "Hello, world!", 5, 0, "", 0},
	{"Empty string", "", 0, 5, "", 1},
	{"NULL input", NULL, 0, 5, NULL, 1},
	{"Partial copy", "Hello, world!", 1, 3, "ell", 0},
	{"Large string", NULL, 0, 0, "AAAAAAAAAA", 0}, // special case
	{"Edge boundary", "abcd", 2, 1, "c", 0}
	};
	const int			total = sizeof(tests) / sizeof(t_test_case);
	const int			special_case_index = 8;
	int					passed;
	int					success;
	char				*result;
	char				*big;
	int					i;

	passed = 0;
	i = 0;
	printf("===== ft_substr tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		if (i == special_case_index)
		{
			big = malloc(10000);
			memset(big, 'A', 9999);
			big[9999] = '\0';
			result = ft_substr(big, 5000, 10);
			SAFE_FREE(big);
		}
		else
		{
			result = ft_substr(tests[i].src, tests[i].start, tests[i].len);
		}
		if (tests[i].allow_null && result == NULL)
			success = 1;
		else if (TEST_STR(tests[i].expected, result))
			success = 1;
		if (success)
		{
			printf(GREEN "[%2d] %-25s -> Success!\n" RESET, i + 1, tests[i].desc);
			passed++;
		}
		else
		{
			if (!result)
				result = "NULL";
			printf(RED "[%2d] %-25s -> Failure! Got: \"%s\"\n" RESET,
				i + 1, tests[i].desc, result);
		}
		SAFE_FREE(result);
		i++;
	}
	printf("\n===== Summary =====\n");
	if (passed == total)
		printf(GREEN "%d/%d tests passed ✅\n" RESET, passed, total);
	else
		printf(RED "%d/%d tests passed ❌\n" RESET, passed, total);
	printf("===================\n");
	return (EXIT_SUCCESS);
}
