/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_itoa.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:35:03 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 13:35:42 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_ITOA_H
# define STRUCT_TEST_ITOA_H
# include "../tests.h"

typedef struct s_test_case_itoa
{
	const char		*desc;
	int				n;
	const char		*expected;
}	t_test_case_itoa;

#endif
