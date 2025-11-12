/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:30:38 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 17:55:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "macros/colors.h"
# include "macros/test_helpers.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include "struct/structs_tests.h"
# include "../libft.h"

t_test_set_result	ft_tests_itoa(void);

t_test_set_result	ft_tests_split(void);

t_test_set_result	ft_tests_strjoin(void);

t_test_set_result	ft_tests_strtrim(void);

t_test_set_result	ft_tests_substr(void);

t_test_set_result	ft_tests_strmapi(void);

t_test_set_result	ft_tests_striteri(void);

t_test_set_result	ft_tests_lstnew(void);

t_test_set_result	ft_tests_lstmap(void);

char				*convert_string(char *s);

int					strscmp(const char **ss1, const char **ss2);

char				*strs_tostring(const char **strs);

void				free_arr(void **arr, size_t size);

t_test_set_result	ft_run_tests(const char *name, t_test *tests,
						unsigned int n);

char	*lst_tostring_char(t_list *lst);

char	*lst_tostring_str(t_list *lst);

char	*lst_tostring_int(t_list *lst);

bool	ft_lsteq(t_list *l1, t_list *l2);

bool	ft_lst_has_cycle(t_list *lst);

#endif
