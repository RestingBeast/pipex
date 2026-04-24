/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:56:27 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 08:17:01 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_int(t_buffer *buffer, t_flag *flags,
		int num, char specifier)
{
	char	*str;
	int		count;

	if (num == 0 && flags->precision && !(flags->precision_width))
		str = ft_strdup("");
	else
		str = ft_itoa_base(num, 10, "0123456789");
	str = process_flags(flags, str, specifier);
	count = copy_string_to_buffer(buffer, str);
	free(str);
	return (count);
}

int	convert_to_hex(t_buffer *buffer, t_flag *flags,
		unsigned int num, char specifier)
{
	char	*str;
	char	*hex_string;
	int		count;

	if (specifier == 'x')
		hex_string = "0123456789abcdef";
	else
		hex_string = "0123456789ABCDEF";
	if (num == 0 && flags->precision && !(flags->precision_width))
		str = ft_strdup("");
	else
		str = ft_itoa_base(num, 16, hex_string);
	if (num == 0)
		flags->hash = 0;
	str = process_flags(flags, str, specifier);
	count = copy_string_to_buffer(buffer, str);
	free(str);
	return (count);
}

int	convert_to_address(t_buffer *buffer, t_flag *flags,
			uintptr_t address, char specifier)
{
	char	*str;
	char	*tmp;
	int		count;

	if (address == 0)
		str = ft_strdup("(nil)");
	else
	{
		str = ft_itoa_unsigned(address, 16, "0123456789abcdef");
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	str = process_flags(flags, str, specifier);
	count = copy_string_to_buffer(buffer, str);
	free(str);
	return (count);
}

int	convert_to_unsigned_int(t_buffer *buffer, t_flag *flags,
		unsigned int num, char specifier)
{
	char	*str;
	int		count;

	if (num == 0 && flags->precision && !(flags->precision_width))
		str = ft_strdup("");
	else
		str = ft_itoa_base(num, 10, "0123456789");
	str = process_flags(flags, str, specifier);
	count = copy_string_to_buffer(buffer, str);
	free(str);
	return (count);
}
