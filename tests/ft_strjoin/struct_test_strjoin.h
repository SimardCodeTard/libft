/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strjoin.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:33:17 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 16:58:36 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRJOIN_H
# define STRUCT_TEST_STRJOIN_H
# include "../tests.h"

typedef struct s_test_case_strjoin
{
	const char		*desc;
	const char		*s1;
	const char		*s2;
	const char		*expected;
	bool			allow_null;
}	t_test_case_strjoin;

#endif
