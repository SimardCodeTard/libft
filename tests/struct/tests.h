/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:21:13 by simard            #+#    #+#             */
/*   Updated: 2025/11/11 16:01:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RESULT_H
# define TEST_RESULT_H
# include "../tests.h"

typedef struct s_test_result
{
	char	*desc;
	char	*expected;
	char	*result;
	bool	success;
}	t_test_result;

typedef struct s_test_set_result
{
	unsigned int	success_count;
	unsigned int	failure_count;
	const char		*name;
}	t_test_set_result;

typedef struct s_test
{
	t_test_result	(*f)(void *);
	void			*params;
}	t_test;


#endif
