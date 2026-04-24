/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:19:07 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 10:59:15 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flags(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->precision_width = 0;
	flags->min_width = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

void	set_flags(t_flag *flags, char c)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
}

static char	*apply_precision(char *str, int precision_width, char specifier)
{
	int	width;

	if (is_numerical_specifier(specifier))
	{
		width = precision_width - ft_strlen(str);
		if (*str == '-')
			width++;
		return (apply_precision_padding(str, width));
	}
	else if (specifier == 's')
		return (truncate_string(str, precision_width));
	return (str);
}

static char	*apply_zero_padding(t_flag *flags, char *str, char specifier)
{
	int		width;
	char	prefix[3];

	prefix[0] = '\0';
	width = flags->min_width - ft_strlen(str);
	if ((*str == '-' || flags->plus || flags->space)
		&& is_decimal(specifier))
		ft_strlcpy(prefix, str, 2);
	else if (flags->hash && is_hexadecimal(specifier))
		ft_strlcpy(prefix, str, 3);
	return (put_zero_padding(str, prefix, width));
}

char	*process_flags(t_flag *flags, char *str, char specifier)
{
	if (flags->precision)
		str = apply_precision(str, flags->precision_width, specifier);
	if (flags->hash && is_hexadecimal(specifier))
		str = apply_alternate_format(str, specifier);
	if (flags->plus && is_decimal(specifier))
		str = prefix_format(str, "+");
	else if (flags->space && is_decimal(specifier))
		str = prefix_format(str, " ");
	if (flags->min_width)
	{
		if (flags->minus)
			str = justify_left(str,
					flags->min_width - ft_strlen(str));
		else if (!(flags->precision) && flags->zero
			&& is_numerical_specifier(specifier))
			str = apply_zero_padding(flags, str, specifier);
		else
			str = justify_right(str,
					flags->min_width - ft_strlen(str));
	}
	return (str);
}
