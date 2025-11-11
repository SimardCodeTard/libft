/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_striteri.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:18:11 by smenard           #+#    #+#             */
/*   Updated: 2025/11/11 16:11:04 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRITERI_H
# define STRUCT_TEST_STRITERI_H

typedef struct s_params_striteri
{
	char	*desc;
	char	*s;
	void	(*f)(unsigned int, char*);
	char	*expected;
}	t_params_striteri;

typedef struct s_test_case_striteri
{
	t_test_result		(*f)(void *);
	t_params_striteri	params;
}	t_test_case_striteri;

#endif
