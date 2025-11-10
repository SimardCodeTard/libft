/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strmapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:03:50 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:12:43 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_strmapi.h"

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

void	ft_tests_strmapi(void)
{
	const t_test_case_strmapi	tests[] = {
	{"To upper", "abcdefghijklmnopqrstuvwxyz", f_toupper,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
	{"To lower", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_tolower,
		"abcdefghijklmnopqrstuvwxyz"},
	{"Add index", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_addindex,
		"ACEGIKMOQSUWY[]_acegikmoqs"},
	};
	const int					total = sizeof(tests)
		/sizeof(t_test_case_strmapi);
	int							passed;
	int							success;
	char						*result;
	int							i;

	passed = 0;
	i = 0;
	printf("===== ft_strmapi tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		result = ft_strmapi(tests[i].s, tests[i].f);
		if (TEST_STR(tests[i].expected, result))
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
