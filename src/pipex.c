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

void	duplicate_fds(int infile, int outfile, int *fd)
{
	fd[0] = dup(infile);
	if (fd[0] == -1)
		return (early_exit());
	close(infile);
	fd[2] = dup(outfile);
	if (fd[2] == -1)
		return (early_exit());
	close(outfile);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	fd[3];

	if (argc != 5)
		return (0);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[1], strerror(errno)), 0);
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[argc - 1],
				strerror(errno)), 0);
	duplicate_fds(infile, outfile, fd);
	spawn_child_1(fd, argv + 2, envp);
	return (0);
}
