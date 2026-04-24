/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_helpers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:36:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 10:58:04 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_zero_padding(char *str, char *prefix, int width)
{
	char	*res;
	char	*padding;

	if (width <= 0)
		return (str);
	padding = create_padding('0', width);
	res = ft_strjoin(padding, str + ft_strlen(prefix));
	free(str);
	free(padding);
	return (put_prefix(res, prefix));
}

char	*apply_precision_padding(char *str, int width)
{
	char	*res;
	char	*padding;
	int		has_sign;

	if (width <= 0)
		return (str);
	has_sign = (*str == '-');
	padding = create_padding('0', width);
	res = ft_strjoin(padding, str + has_sign);
	if (has_sign)
		res = put_prefix(res, "-");
	free(str);
	free(padding);
	return (res);
}

char	*truncate_string(char *str, int len)
{
	char	*res;

	if (!str || len == 0)
	{
		free(str);
		res = ft_strdup("");
		return (res);
	}
	res = ft_substr(str, 0, len);
	free(str);
	return (res);
}
