/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_helpers_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:36:13 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 11:04:02 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_null_terminator(int left, char *str)
{
	char	*res;
	int		len;

	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (left)
	{
		res[0] = '\0';
		ft_memcpy(res + 1, str, len);
	}
	else
	{
		ft_memcpy(res, str, len + 1);
		res[len] = '\0';
	}
	free(str);
	return (res);
}

int	convert_to_char(t_buffer *buffer, t_flag *flags,
	int c, char specifier)
{
	char	*str;
	int		count;
	int		size;

	count = 0;
	str = convert_char_to_string(c);
	flags->min_width -= 1 - ft_strlen(str);
	str = process_flags(flags, str, specifier);
	size = ft_strlen(str);
	if (c == '\0')
	{
		str = handle_null_terminator(flags->minus, str);
		size++;
	}
	count = copy_mem_to_buffer(buffer, str, size);
	free(str);
	return (count);
}

int	convert_to_string(t_buffer *buffer, t_flag *flags,
	char *str, char specifier)
{
	int		count;

	if (!str && (!(flags->precision) || flags->precision_width > 5))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = process_flags(flags, str, specifier);
	count = copy_string_to_buffer(buffer, str);
	free(str);
	return (count);
}
