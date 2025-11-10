/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simard <simard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:30:38 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 21:28:20 by simard           ###   ########.fr       */
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
# include "struct/tests.h"
# include "../libft.h"

t_test_set_result	ft_tests_itoa(void);

t_test_set_result	ft_tests_split(void);

t_test_set_result	ft_tests_strjoin(void);

t_test_set_result	ft_tests_strtrim(void);

t_test_set_result	ft_tests_substr(void);

t_test_set_result	ft_tests_strmapi(void);

t_test_set_result	ft_tests_striteri(void);

char				*convert_string(char *s);

int					strscmp(const char **ss1, const char **ss2);

char				*strs_tostring(const char **strs);

void				free_arr(void **arr, size_t size);

t_test_set_result	ft_run_tests(const char *name, t_test *tests,
	unsigned int n);

#endif
