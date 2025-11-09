/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 15:30:30 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CASE_STRING_H
# define TEST_CASE_STRING_H
# include <unistd.h>
# include <stdbool.h>
typedef struct s_test_case_string
{
	const char		*desc;
	const char		*src;
	unsigned int	start;
	size_t			len;
	const char		*expected;
	bool			allow_null; // 1 = NULL is acceptable result
}	t_test_case_string;

#endif
