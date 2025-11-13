/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_split.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simard <simard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:28:05 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 21:27:42 by simard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_SPLIT_H
# define STRUCT_TEST_SPLIT_H

typedef struct s_params_split
{
	const char	*desc;
	const char	*s;
	char		c;
	const char	**expected;
}	t_params_split;

typedef struct s_test_case_split
{
	t_test_result	(*f)(void *);
	t_params_split	params;
}	t_test_case_split;

#endif
