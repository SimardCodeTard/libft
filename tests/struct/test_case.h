/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:09:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 15:09:45 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CASE_H
# define TEST_CASE_H
# include <unistd.h>

typedef struct s_test_case
{
	const char		*desc;
	const char		*src;
	unsigned int	start;
	size_t			len;
	const char		*expected;
	int				allow_null; // 1 = NULL is acceptable result
}	t_test_case;

#endif
