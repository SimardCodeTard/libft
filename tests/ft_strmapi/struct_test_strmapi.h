/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_strmapi.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:01:05 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:26:56 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRMAPI_H
# define STRUCT_TEST_STRMAPI_H

typedef struct s_params_strmapi
{
	char	*desc;
	char	*s;
	char	(*f)(unsigned int, char);
	char	*expected;
}	t_params_strmapi;

typedef struct s_test_case_strmapi
{
	t_test_result		(*f)(void *);
	t_params_strmapi	params;
}	t_test_case_strmapi;

#endif
