/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:48:40 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 20:46:30 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strtrim.h"

int	main(void)
{
	const t_test_case_strtrim	tests[] = {
	{"Trim '\\n' at the end", "Hello, world!\n", "\n", "Hello, world!"},
	{"Trim '\\n' in the middle", "Hello,\n world!", "\n", "Hello,\n world!"},
	{"Trim '\\n' in the middle and at the end", "Hello,\n world!\n", "\n",
		"Hello,\n world!"},
	{"Trim '\\n' with an already trimmed string", "Hello, world!", "\n",
		"Hello, world!"},
	{"Empty s1", "", "\n", ""},
	{"Empty set", "Hello, world!", "", "Hello, world!"},
	{"Nulbyte in set", "Hello, world!", "\0", "Hello, world!"},
	{"Random bullshit", "\n\n\t\t\rH\tel\t\t\nlo, w\t\to\nrl\rd\r!\n\n\t\r\n",
		"\n\t\r",
		"H\tel\t\t\nlo, w\t\to\nrl\rd\r!"},
	{"NULL s1", NULL, "\n", ""},
	{"Fully trimmed", "          ", " ", ""},
	};
	const int					total = sizeof(tests)
		/ sizeof(t_test_case_strtrim);
	int							passed;
	int							success;
	char						*result;
	int							i;

	passed = 0;
	i = 0;
	printf("===== ft_strtrim tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		result = ft_strtrim(tests[i].s1, tests[i].set);
		if (TEST_STR(tests[i].expected, result))
			success = 1;
		printf("Test [%2d] %-40s -> ", i + 1, tests[i].desc);
		if (success)
		{
			printf(GREEN "Success!\n" RESET);
			passed++;
		}
		else
		{
			if (!result)
				result = "NULL";
			printf(RED "Failure! Got: \"%s\" expected : \"%s\"\n"
				RESET, convert_string(result), tests[i].expected);
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
