/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_split.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:28:05 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 21:40:31 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_SPLIT_H
# define STRUCT_TEST_SPLIT_H

typedef struct s_test_case_split
{
	const char		*desc;
	const char		*s;
	const char		c;
	const char		**expected;
}	t_test_case_split;

#endif
