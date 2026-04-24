/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:17:19 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/05 20:13:52 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long n, int base)
{
	int	res;

	res = 1;
	while ((n / base) > 0)
	{
		res++;
		n /= base;
	}
	return (res);
}

static int	count_digits_unsigned(unsigned long n, int base)
{
	int	res;

	res = 1;
	while ((n / base) > 0)
	{
		res++;
		n /= base;
	}
	return (res);
}

static int	check_negative(long *n)
{
	if (*n < 0)
	{
		*n = (*n) * (-1);
		return (1);
	}
	return (0);
}

char	*ft_itoa_base(long n, int base, char *base_string)
{
	int		len;
	int		is_neg;
	int		i;
	char	*res;

	is_neg = check_negative(&n);
	len = is_neg + count_digits(n, base);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[len - i - 1] = base_string[n % base];
		n /= base;
		i++;
	}
	if (is_neg)
		res[0] = '-';
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_unsigned(unsigned long n, int base, char *base_string)
{
	int		len;
	int		i;
	char	*res;

	len = count_digits_unsigned(n, base);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[len - i - 1] = base_string[n % base];
		n /= base;
		i++;
	}
	res[i] = '\0';
	return (res);
}
