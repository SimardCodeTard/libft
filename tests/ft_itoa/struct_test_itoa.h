/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_itoa.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simard <simard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:35:03 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 20:49:44 by simard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_ITOA_H
# define STRUCT_TEST_ITOA_H
# include "../tests.h"

typedef struct s_params_itoa
{
	char	*desc;
	int		n;
	char	*expected;
}	t_params_itoa;

typedef struct s_test_case_itoa
{
	t_test_result	(*f)(void *);
	t_params_itoa	params;
}	t_test_case_itoa;

#endif
