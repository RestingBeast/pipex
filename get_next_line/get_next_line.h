/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:31:24 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/14 20:17:48 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_leftover
{
	char	*data;
	size_t	capacity;
}	t_leftover;

char	*get_next_line(int fd);

// utils
int		gnl_strchr(char *str, int c);
int		gnl_strlen(char *str);
void	gnl_strcat(char *dest, char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_extract(char *str, char delimiter);

#endif
