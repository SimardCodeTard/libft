/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:34:02 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 21:53:24 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_split.h"

int	main(void)
{
	static const char		*expected_no_split[] = {"Hello, world!", NULL};
	static const char		*expected_split_2_words[]
		= {"Hello", "world!", NULL};
	static const char		*expected_split_3_words[]
		= {"Hello", "world!", "Hi, mom!", NULL};
	static const char		*expected_split_0_words[] = {NULL};
	const t_test_case_split	tests[] = {
	{"No split", "Hello, world!", ';', expected_no_split},
	{"Basic split", "Hello;world!", ';', expected_split_2_words},
	{"Split with surrounding separators", ";Hello, world!;", ';',
		expected_split_2_words},
	{"Split with surrounding separators and multiple words", ";Hello;world!;",
		';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words (uneven)",
		";;;Hello;world!;Hi, mom ,;;", ';', expected_split_3_words},
	{"Split with empty string", "", ';', expected_split_0_words},
	{"Split with NULL", NULL, ';', expected_split_0_words},
	};
	const int				total = sizeof(tests)
		/ sizeof(t_test_case_split);
	int						passed;
	int						success;
	char					**result;
	int						i;

	passed = 0;
	i = 0;
	printf("===== ft_strjoin tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		result = ft_split(tests[i].s, tests[i].c);
		if (!strscmp(tests[i].expected, result))
			success = 1;
		if (success)
		{
			printf(GREEN "[%d] %-25s -> Success!\n" RESET, i + 1,
				tests[i].desc);
			passed++;
		}
		else
		{
			if (!result)
				result = "NULL";
			printf(RED "[%d] %-25s -> Failure! Got: \"%s\" expected : \"%s\"\n"
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
	printf("===================\n");
	return (EXIT_SUCCESS);
}
