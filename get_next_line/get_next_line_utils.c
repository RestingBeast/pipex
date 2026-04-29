/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:53 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/27 15:42:44 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	gnl_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	gnl_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = gnl_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;

	res = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (s1)
		gnl_strcat(res, s1);
	gnl_strcat(res, s2);
	free(s1);
	return (res);
}

char	*gnl_extract(char *str, char delimiter)
{
	int		len;
	char	*res;
	int		i;

	if (gnl_strchr(str, delimiter))
		len = gnl_strchr(str, delimiter);
	else
		len = gnl_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != delimiter && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == delimiter)
		res[i++] = delimiter;
	res[i] = '\0';
	return (res);
}
