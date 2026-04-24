/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:03:59 by kkhant-z          #+#    #+#             */
/*   Updated: 2025/12/17 19:04:02 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	int			count;

	count = 0;
	va_start(args, format);
	buffer.size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			format += set_flags_and_convert(format,
					&buffer, &count, args);
		else
			count += copy_to_buffer(&buffer, *format);
		format++;
	}
	va_end(args);
	count += flush_buffer(&buffer);
	return (count);
}
