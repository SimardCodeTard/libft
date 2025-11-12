/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_lstnew.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:13:58 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 17:15:04 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_LSTNEW_H
# define STRUCT_TEST_LSTNEW_H
# include "../tests.h"

typedef enum	e_content_type
{
	FT_CTYPE_CHAR,
	FT_CTYPE_STRING,
	FT_CTYPE_INT,
}	t_content_type;

typedef struct s_params_lstnew
{
	char			*desc;
	void			*content;
	void			*expected;
	t_content_type	content_type;
}	t_params_lstnew;

typedef struct s_test_case_lstnew
{
	t_test_result	(*f)(void *);
	t_params_lstnew	params;
}	t_test_case_lstnew;

#endif
