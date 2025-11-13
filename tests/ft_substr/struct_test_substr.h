/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_substr.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:54:09 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_SUBSTR_H
# define STRUCT_TEST_SUBSTR_H
# include "../tests.h"

typedef struct s_params_substr
{
	char		*desc;
	char		*src;
	unsigned int	start;
	size_t			len;
	char		*expected;
}	t_params_substr;

typedef struct s_test_case_substr
{
	t_test_result		(*f)(void *);
	t_params_substr		params;
}	t_test_case_substr;

#endif
