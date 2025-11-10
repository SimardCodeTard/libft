/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strmapi.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:01:05 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:03:40 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRMAPI_H
# define STRUCT_TEST_STRMAPI_H

typedef struct s_test_case_strmapi
{
	const char	*desc;
	const char	*s;
	char		(*f)(unsigned int, char);
	const char	*expected;
}	t_test_case_strmapi;

#endif
