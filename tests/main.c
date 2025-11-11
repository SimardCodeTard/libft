/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:33:35 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:52:33 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	const t_test_set	sets[] = {
		ft_tests_itoa,
		ft_tests_split,
		ft_tests_striteri,
		ft_tests_strjoin,
		ft_tests_strmapi,
		ft_tests_strtrim,
		ft_tests_substr,
	};
	const size_t		total = sizeof(sets) / sizeof(t_test_set);
	t_test_set_result	*results = calloc(total, sizeof(t_test_set_result));
	uint16_t			i = 0;
	uint16_t			j = 0;
	uint16_t			k = 0;
	unsigned int		failed_tests_count = 0;
	unsigned int		successful_tests_count = 0;
	unsigned int		failed_sets_count = 0;
	unsigned int		successful_sets_count = 0;
	const char			**failed_sets;
	const char			**successful_sets;

	while (i < total)
	{
		results[i] = sets[i]();
		failed_tests_count += results[i].failure_count;
		successful_tests_count += results[i].success_count;
		if (results[i].failure_count)
			failed_sets_count++;
		else
			successful_sets_count++;
		i++;
	}
	i = 0;
	failed_sets = calloc(failed_sets_count + 1, sizeof(char *));
	successful_sets = calloc(successful_sets_count + 1, sizeof(char *));
	while (i < total)
	{
		if (results[i].failure_count)
			failed_sets[j++] = results[i].name;
		else
			successful_sets[k++] = results[i].name;
		i++;
	}
	printf("\n========== Summary ==========\n\n");
	if (!failed_tests_count && !successful_tests_count)
	{
		printf(KYEL "Did not run any sets...\n" KNRM);
		free(results);
		free(failed_sets);
		free(successful_sets);
		return (EXIT_SUCCESS);
	}
	if (failed_tests_count)
		printf(KRED "❌ %s%d%s / %s%d%s tests failed across %s%d%s files!\n" KNRM,
			KYEL, failed_tests_count, KRED, KYEL, failed_tests_count + successful_tests_count,
			KRED, KYEL, failed_sets_count + successful_sets_count, KRED);
	else
		printf(KGRN"✅ Successfuly ran %s%d%s tests across %s%d%s files!\n" KNRM,
			KYEL,successful_tests_count, KGRN, KYEL, successful_sets_count,
			KGRN);
	if (successful_sets_count)
	{
		printf(KGRN "Passed sets :\n");
		i = 0;
		while (i < successful_sets_count)
		{
			printf("%s", successful_sets[i]);
			if (i < successful_sets_count - 1)
				printf(", ");
			else
				printf("\n");
			i++;
		}
		printf(KNRM);
	}
	if (failed_sets_count)
	{
		printf(KRED "Failed sets :\n");
		i = 0;
		while (i < failed_sets_count)
		{
			printf("%s", failed_sets[i]);
			if (i < failed_sets_count - 1)
				printf(", ");
			else
				printf("\n");
			i++;
		}
		printf(KNRM);
	}
	free(results);
	free(failed_sets);
	free(successful_sets);
	return (EXIT_SUCCESS);
}
