/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test_striteri.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:18:11 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:24:49 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TEST_STRITERI_H
# define STRUCT_TEST_STRITERI_H

typedef struct s_test_case_striteri
{
	const char	*desc;
	const char	*s;
	void		(*f)(unsigned int, char*);
	const char	*expected;
}	t_test_case_striteri;

#endif
