/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strtrim.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 17:59:30 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRTRIM_H
# define STRUCT_TEST_STRTRIM_H
# include "../tests.h"

typedef struct s_test_case_strtrim
{
	const char	*desc;
	const char	*s1;
	const char	*set;
	const char	*expected;
}	t_test_case_strtrim;

#endif
