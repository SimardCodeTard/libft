/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_substr.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 16:35:02 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_SUBSTR_H
# define STRUCT_TEST_SUBSTR_H
# include "../tests.h"

typedef struct s_test_case_substr
{
	const char		*desc;
	const char		*src;
	unsigned int	start;
	size_t			len;
	const char		*expected;
	bool			allow_null; // 1 = NULL is acceptable result
}	t_test_case_substr;

#endif
