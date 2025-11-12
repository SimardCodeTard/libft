/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_lstmap.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:13:58 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 17:31:59 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_LSTMAP_H
# define STRUCT_TEST_LSTMAP_H
# include "../tests.h"

typedef struct s_params_lstmap
{
	char			*desc;
	t_list			*lst;
	void *			(*f)(void *);
	void 			(*del)(void *);
	t_list			*expected;
}	t_params_lstmap;

typedef struct s_test_case_lstmap
{
	t_test_result	(*f)(void *);
	t_params_lstmap	params;
}	t_test_case_lstmap;

#endif
