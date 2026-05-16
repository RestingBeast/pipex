/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:20:25 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/05/16 11:20:26 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_delimiter(char *line, char *delimiter)
{
	size_t	len;

	len = ft_strlen(delimiter);
	if (len != ft_strlen(line) - 1)
		return (0);
	return (ft_strncmp(line, delimiter, len) == 0);
}

int	ft_streq(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, len) == 0);
}
