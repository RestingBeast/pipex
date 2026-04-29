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

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
//	int	i;

	if (argc != 4)
		return (0);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[1], strerror(errno)), 0);
	outfile = open(argv[argc - 1], O_CREAT | O_RDWR);
	if (outfile == -1)
		return (ft_printf("pipex: %s: %s\n", argv[1], strerror(errno)), 0);
//	i = 0;
//	while (i++ < argc - 2)
//		spawn_child();
	spawn_child(infile, outfile, argv[2], envp);
	return (0);
}
