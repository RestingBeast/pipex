/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:00:53 by kkhant-z          #+#    #+#             */
/*   Updated: 2025/11/30 20:00:54 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	res;

	res = 1;
	while ((n / 10) > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static int	check_negative(int *n)
{
	if (*n < 0)
	{
		*n = (*n) * (-1);
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		len;
	int		is_neg;
	int		i;
	char	*res;

	len = 0;
	is_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = check_negative(&n);
	len = is_neg + count_digits(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (is_neg)
		res[0] = '-';
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-1234));
	return (0);
}
*/
