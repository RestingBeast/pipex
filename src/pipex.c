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
	int			fds[2];
	int			last_pid;
	int			prev_read;
	t_outfile	outfile;

	if (pipe(fds) == -1)
		early_exit(NULL);
	prev_read = spawn_first_child(argv[1], fds, argv[2], envp);
	outfile.filename = argv[argc - 1];
	outfile.flags = O_RDWR | O_CREAT | O_TRUNC;
	last_pid = spawn_last_child(prev_read, &outfile, argv[3], envp);
	kill_zombies(3, last_pid);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (1);
	start_pipex(argc, argv, envp);
	return (0);
}
