/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:58:24 by smenard           #+#    #+#             */
/*   Updated: 2025/11/09 14:58:38 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HELPERS_H
# define TEST_HELPERS_H
# define TEST_STR(expected, got) ((expected == NULL && got == NULL)\
	|| (expected && got && strcmp(expected, got) == 0))
# define SAFE_FREE(ptr) do { if (ptr) free(ptr); } while (0)
#endif
