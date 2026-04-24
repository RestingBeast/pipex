/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:28:14 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 10:55:55 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prefix_format(char *str, char *prefix)
{
	if (*str == '-')
		return (str);
	return (put_prefix(str, prefix));
}

char	*apply_alternate_format(char *str, char specifier)
{
	char	prefix[3];

	prefix[0] = '0';
	prefix[1] = specifier;
	prefix[2] = '\0';
	return (put_prefix(str, prefix));
}

char	*justify_left(char *str, int width)
{
	char	*res;
	char	*padding;

	if (width <= 0)
		return (str);
	padding = create_padding(' ', width);
	res = ft_strjoin(str, padding);
	free(str);
	free(padding);
	return (res);
}

char	*justify_right(char *str, int width)
{
	char	*res;
	char	*padding;

	if (width <= 0)
		return (str);
	padding = create_padding(' ', width);
	res = ft_strjoin(padding, str);
	free(str);
	free(padding);
	return (res);
}
