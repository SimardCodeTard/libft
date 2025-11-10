/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:18:00 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 14:29:08 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	numlen(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	bool	is_neg;
	int		i;

	is_neg = n < 0;
	len = numlen(ft_abs((long) n));
	if (is_neg)
		len++;
	i = 0;
	n = ft_abs(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (n == INT_MIN)
		return (ft_memcpy(res, "-2147483648", 11));
	if (!res)
		return (ft_calloc(1, sizeof(char)));
	while (i < len)
	{
		res[len - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
