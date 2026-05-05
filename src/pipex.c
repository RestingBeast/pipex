/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:23:38 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/24 17:23:39 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_error(char *filename)
{
	ft_printf("pipex: %s: %s\n", filename, strerror(errno));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	prev_read;
	int	i;

	if (argc != 5)
		return (0);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (file_error(argv[1]));
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (file_error(argv[argc - 1]));
	i = 1;
	prev_read = infile;
	while (++i < argc - 1)
	{
		
		prev_read = 
	}
	spawn_child(fd, argv + 2, envp);
	return (0);
}
