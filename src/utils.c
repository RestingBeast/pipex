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

void	spawn_child(int read, int *fds, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		early_exit();
	if (pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
			early_exit();
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			early_exit();
		close(read);
		close(fds[0]);
		close(fds[1]);
		parse_cmd_and_execute(cmd, envp);
	}
	else
	{
		close(read);
		close(fds[1]);
	}
}

void	spawn_last_child(int read, int write, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		early_exit();
	if (pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
			early_exit();
		if (dup2(write, STDOUT_FILENO) == -1)
			early_exit();
		close(read);
		close(write);
		parse_cmd_and_execute(cmd, envp);
	}
	else
	{
		close(read);
		close(write);
	}
}

int	exe_cmd(int prev_fd, char *cmd, char **envp)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (early_exit(), 0);
	spawn_child(prev_fd, fds, cmd, envp);
	return (fds[0]);
}

void	kill_zombies(int count)
{
	int	status;

	while (count-- > 1)
		waitpid(-1, &status, 0);
}
