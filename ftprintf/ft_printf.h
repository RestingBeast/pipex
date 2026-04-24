/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:20 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/08 10:56:17 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFFER_SIZE 1024

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	int		size;
}	t_buffer;

typedef struct s_flag
{
	int	minus;
	int	zero;
	int	precision;
	int	precision_width;
	int	min_width;
	int	hash;
	int	space;
	int	plus;
}	t_flag;

int		ft_printf(const char *format, ...);

// buffer
int		copy_to_buffer(t_buffer *buffer, int c);
int		copy_string_to_buffer(t_buffer *buffer, char *str);
int		copy_mem_to_buffer(t_buffer *buffer, char *str, int size);
int		flush_buffer(t_buffer *buffer);

// checks
int		is_flag(char c);
int		is_specifier(char c);
int		is_numerical_specifier(char c);
int		is_decimal(char c);
int		is_hexadecimal(char c);

// conversions
int		set_flags_and_convert(const char *format,
			t_buffer *buffer, int *count, va_list args);

// conversion_helpers
int		convert_to_char(t_buffer *buffer, t_flag *flags,
			int c, char specifier);
int		convert_to_string(t_buffer *buffer, t_flag *flags,
			char *str, char specifier);
int		convert_to_int(t_buffer *buffer, t_flag *flags,
			int num, char specifier);
int		convert_to_hex(t_buffer *buffer,
			t_flag *flags, unsigned int num, char specifier);
int		convert_to_address(t_buffer *buffer,
			t_flag *flags, uintptr_t address, char specifier);
int		convert_to_unsigned_int(t_buffer *buffer,
			t_flag *flags, unsigned int num, char specifier);

// flags
void	initialize_flags(t_flag *flags);
void	set_flags(t_flag *flags, char c);
char	*process_flags(t_flag *flags, char *str, char specifier);

// flags_helpers
char	*prefix_format(char *str, char *prefix);
char	*apply_alternate_format(char *str, char specifier);
char	*justify_left(char *str, int width);
char	*justify_right(char *str, int width);
char	*put_zero_padding(char *str, char *prefix, int width);
char	*apply_precision_padding(char *str, int width);
char	*truncate_string(char *str, int len);

// utils
char	*ft_itoa_base(long n, int base, char *base_string);
char	*ft_itoa_unsigned(unsigned long n, int base, char *base_string);
char	*convert_char_to_string(char c);
char	*put_prefix(char *str, char *prefix);
char	*create_padding(char padding, int width);

#endif
