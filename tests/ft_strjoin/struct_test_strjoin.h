/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strjoin.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:33:17 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:17:45 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRJOIN_H
# define STRUCT_TEST_STRJOIN_H
# include "../tests.h"

typedef struct s_params_strjoin
{
	char	*desc;
	char	*s1;
	char	*s2;
	char	*expected;
}	t_params_strjoin;

typedef struct s_test_case_strjoin
{
	t_test_result		(*f)(void *);
	t_params_strjoin	params;
}	t_test_case_strjoin;

#endif
