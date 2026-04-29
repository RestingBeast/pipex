/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:33:39 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/27 20:33:48 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	early_exit(void)
{
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	spawn_child(int outfile)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (early_exit());
	pid = fork();
	if (pid == -1)
		return (early_exit());
	if (pid == 0)
	{
		close(fd[1]);
		char *line = get_next_line(fd[0]);
		if (line != NULL)
			write(outfile , "success\n", 8);
		close(fd[0]);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[0]);
		ft_putstr_fd("Hello, World\n", fd[1]);
		close(fd[1]);
	}
}
