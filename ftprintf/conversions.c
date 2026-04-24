/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:57:18 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 08:06:43 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_format(t_buffer *buffer, t_flag *flags,
			char specifier, va_list args)
{
	if (specifier == 'c')
		return (convert_to_char(buffer, flags, va_arg(args, int), specifier));
	else if (specifier == '%')
		return (convert_to_char(buffer, flags, '%', specifier));
	else if (specifier == 's')
		return (convert_to_string(buffer, flags,
				va_arg(args, char *), specifier));
	else if (specifier == 'd' || specifier == 'i')
		return (convert_to_int(buffer, flags, va_arg(args, int), specifier));
	else if (specifier == 'u')
		return (convert_to_unsigned_int(buffer, flags,
				va_arg(args, unsigned int), specifier));
	else if (specifier == 'X' || specifier == 'x')
		return (convert_to_hex(buffer, flags, va_arg(args, int), specifier));
	else if (specifier == 'p')
		return (convert_to_address(buffer, flags,
				(uintptr_t)va_arg(args, void *), specifier));
	return (0);
}

int	set_flags_and_convert(const char *format, t_buffer *buffer,
		int *count, va_list args)
{
	t_flag	flags;
	int		i;

	initialize_flags(&flags);
	i = 1;
	while (is_flag(format[i]))
		set_flags(&flags, format[i++]);
	while (ft_isdigit(format[i]))
		flags.min_width = (flags.min_width * 10) + (format[i++] - '0');
	if (format[i] == '.')
	{
		flags.precision = 1;
		while (ft_isdigit(format[++i]))
			flags.precision_width = (flags.precision_width * 10)
				+ (format[i] - '0');
	}
	if (is_specifier(format[i]))
		*count += convert_format(buffer, &flags, format[i], args);
	return (i);
}
