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

int	main(int argc, char **argv)
{
	int		infile;
	int		outfile;
	// pid_t	pid;

	if (argc != 3)
		return (0);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[1], strerror(errno)), 0);
	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY);
	if (outfile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[1], strerror(errno)), 0);
	spawn_child(outfile);
	close(infile);
	close(outfile);
	return (0);
}
