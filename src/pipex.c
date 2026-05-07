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

static void	start_pipex(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	prev_read;
	int	i;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		ft_printf("pipex: %s: %s\n", argv[1], strerror(errno));
		return ;
	}
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		ft_printf("pipex: %s: %s\n", argv[argc - 1], strerror(errno));
		return ;
	}
	i = 1;
	prev_read = infile;
	while (++i < argc - 2)
		prev_read = exe_cmd(prev_read, argv[i], envp);
	spawn_last_child(prev_read, outfile, argv[i], envp);
	kill_zombies(i);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);
	start_pipex(argc, argv, envp);
	return (0);
}
