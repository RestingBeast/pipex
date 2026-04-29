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

void	free_double_ptr(char **argv)
{
	int	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

void	spawn_child(int read_fd, int write_fd, char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (early_exit());
	if (dup2(read_fd, fd[0]) == -1)
		return (close(read_fd), early_exit());
	if (dup2(write_fd, fd[1]) == -1)
		return (close(write_fd), early_exit());
	pid = fork();
	if (pid == -1)
		return (early_exit());
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			_exit(EXIT_FAILURE);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			_exit(EXIT_FAILURE);
		close(fd[0]);
		close(fd[1]);
		parse_cmd_and_execute(cmd, envp);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
	}
}
