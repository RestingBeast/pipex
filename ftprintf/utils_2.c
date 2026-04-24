/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:14:56 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 09:43:12 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char_to_string(char c)
{
	char	*res;

	if (c == '\0')
		return (ft_strdup(""));
	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*put_prefix(char *str, char *prefix)
{
	char	*res;

	res = ft_strjoin(prefix, str);
	free(str);
	return (res);
}

char	*create_padding(char padding, int width)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(width + 1);
	if (!res)
		return (NULL);
	while (i < width)
	{
		res[i] = padding;
		i++;
	}
	res[i] = '\0';
	return (res);
}
