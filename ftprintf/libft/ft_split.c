/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:17:04 by kkhant-z          #+#    #+#             */
/*   Updated: 2025/11/26 14:17:07 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static void	ft_free_mem(char **res, int i)
{
	while (i-- > 0)
		free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		words;
	char	**res;

	words = ft_count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_word_len(s, c);
		res[i] = ft_substr(s, 0, len);
		if (res[i] == NULL)
		{
			return (ft_free_mem(res, i), NULL);
		}
		s += len + 1;
		i++;
	}
	res[i] = NULL;
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s = "      split       this for   me  !       ";
	printf("%d\n", ft_count_words(s, ' '));
	return (0);
}
*/
