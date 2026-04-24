/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:17:03 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/07 18:14:52 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	copy_to_buffer(t_buffer *buffer, int c)
{
	int	count;

	count = 0;
	if (buffer->size >= BUFFER_SIZE)
		count = flush_buffer(buffer);
	buffer->data[(buffer->size)++] = c;
	return (count);
}

int	copy_string_to_buffer(t_buffer *buffer, char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count += copy_to_buffer(buffer, *str);
		str++;
	}
	return (count);
}

int	copy_mem_to_buffer(t_buffer *buffer, char *str, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += copy_to_buffer(buffer, str[i]);
		i++;
	}
	return (count);
}

int	flush_buffer(t_buffer *buffer)
{
	int	count;

	count = buffer->size;
	buffer->size = 0;
	write(1, buffer->data, count);
	return (count);
}
