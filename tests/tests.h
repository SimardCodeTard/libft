/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:30:38 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:21:15 by smenard          ###   ########.fr       */
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
# include "../libft.h"

void	ft_tests_itoa(void);

void	ft_tests_split(void);

void	ft_tests_strjoin(void);

void	ft_tests_strtrim(void);

void	ft_tests_substr(void);

void	ft_tests_strmapi(void);

void	ft_tests_striteri(void);

char	*convert_string(char *s);

int		strscmp(const char **ss1, const char **ss2);

void	print_strs(char **strs);

void	free_arr(void **arr, size_t size);

#endif
