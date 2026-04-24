/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:31:59 by kkhant-z          #+#    #+#             */
/*   Updated: 2025/11/26 12:32:38 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char const *set, char c)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_in_set(set, s1[start]))
		start++;
	while (end >= start && ft_in_set(set, s1[end]))
		end--;
	res = malloc(end - start + 1 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 1 + 1);
	return (res);
}
