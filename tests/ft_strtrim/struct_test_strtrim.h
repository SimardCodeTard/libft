/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strtrim.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:44:22 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRTRIM_H
# define STRUCT_TEST_STRTRIM_H

typedef struct s_params_strtrim
{
	char	*desc;
	char	*s1;
	char	*set;
	char	*expected;
}	t_params_strtrim;

typedef struct s_test_case_strtrim
{
	t_test_result		(*f)(void *);
	t_params_strtrim	params;
}	t_test_case_strtrim;

#endif
