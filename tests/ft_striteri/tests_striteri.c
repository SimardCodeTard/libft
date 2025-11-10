/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_striteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:18:51 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:23:40 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "struct_test_striteri.h"

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

void	ft_tests_striteri(void)
{
	const t_test_case_striteri	tests[] = {
	{"To upper", "abcdefghijklmnopqrstuvwxyz", f_toupper_iteri,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
	{"To lower", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_tolower_iteri,
		"abcdefghijklmnopqrstuvwxyz"},
	{"Add index", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", f_addindex_iteri,
		"ACEGIKMOQSUWY[]_acegikmoqs"},
	};
	const int					total = sizeof(tests)
		/sizeof(t_test_case_striteri);
	int							passed;
	int							success;
	char						*result;
	int							i;

	passed = 0;
	i = 0;
	printf("===== ft_striteri tests =====\n\n");
	while (i < total)
	{
		result = NULL;
		success = 0;
		ft_striteri((char *) tests[i].s, tests[i].f);
		result = (char *) tests[i].s;
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
		i++;
	}
	printf("\n===== Summary =====\n");
	if (passed == total)
		printf(GREEN "%d/%d tests passed ✅\n" RESET, passed, total);
	else
		printf(RED "%d/%d tests passed ❌\n" RESET, passed, total);
	printf("===================\n\n\n");
}
