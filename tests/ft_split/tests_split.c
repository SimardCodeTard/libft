/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:34:02 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 14:41:26 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_split.h"

void	ft_tests_split(void)
{
	static const char		*expected_no_split[] = {"Hello, world!", NULL};
	static const char		*expected_split_2_words[]
		= {"Hello", "world!", NULL};
	static const char		*expected_split_3_words[]
		= {"Hello", "world!", "Hi, mom!", NULL};
	static const char		*expected_split_0_words[] = {NULL};
	static const char		*expected_split_full_sep[] = {NULL};
	const t_test_case_split	tests[] = {
	{"No split", "Hello, world!", ';', expected_no_split},
	{"Basic split", "Hello;world!", ';', expected_split_2_words},
	{"Split with surrounding separators", ";Hello, world!;", ';',
		expected_no_split},
	{"Split with surrounding separators and multiple words", ";Hello;world!;",
		';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words",
		";;;Hello;world!;;;", ';', expected_split_2_words},
	{"Split with multiple surrounding separators and multiple words (uneven)",
		";;;Hello;world!;Hi, mom!;;", ';', expected_split_3_words},
	{"Split with empty string", "", ';', expected_split_0_words},
	{"Split with NULL", NULL, ';', expected_split_0_words},
	{"Split with only sep", ";;;;;;;;;;", ';', expected_split_full_sep},
	};
	const int				total = sizeof(tests)
		/ sizeof(t_test_case_split);
	int						passed;
	int						success;
	char					**result;
	int						i;

	passed = 0;
	i = 0;
	printf("===== ft_split tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		result = ft_split(tests[i].s, tests[i].c);
		if (!strscmp(tests[i].expected, (const char **) result))
			success = 1;
		if (success)
		{
			printf(GREEN "[%2d] %-80s -> Success!\n%s", i + 1, tests[i].desc,
				RESET);
			passed++;
		}
		else
		{
			if (!result)
			{
				printf(RED "[%2d] %-80s -> Failure!%s\nFor s = \"%s\"\nGot:\nNULL\nExpected:\n",
					i + 1, tests[i].desc, RESET, tests[i].s);
				print_strs((char **) tests[i].expected);
				printf("\n");
			}
			else
			{
				printf(RED "[%2d] %-75s -> Failure!%s\nFor s = \"%s\"\nGot:\n", i + 1,
					tests[i].desc, RESET, tests[i].s);
				print_strs(result);
				printf("\nExpected:\n");
				print_strs((char **) tests[i].expected);
				printf("\n" RESET);
			}
		}
		free_arr((void **)result, sizeof(char));
		i++;
	}
	printf("\n===== Summary =====\n");
	if (passed == total)
		printf(GREEN "%d/%d tests passed ✅\n" RESET, passed, total);
	else
		printf(RED "%d/%d tests passed ❌\n" RESET, passed, total);
	printf("===================\n\n\n");
}
