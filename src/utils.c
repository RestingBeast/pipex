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

void	spawn_child(int read, int *fds, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (early_exit());
	if (pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
			_exit(EXIT_FAILURE);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			_exit(EXIT_FAILURE);
		close(read);
		close(fds[0]);
		close(fds[1]);
		parse_cmd_and_execute(cmd, envp);
	}
	else
	{
		close(fds[1]);
	}
}

int	spawn_last_child(int read, int write, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (early_exit(), 0);
	if (pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		if (dup2(write, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(read);
		close(write);
		parse_cmd_and_execute(cmd, envp);
	}
	else
	{
		close(read);
		close(write);
	}
	return (pid);
}

void	kill_zombies(int count, int last_pid)
{
	int	status;
	int	exit_status;

	waitpid(last_pid, &exit_status, 0);
	while (--count > 1)
		waitpid(-1, &status, 0);
	exit(exit_status);
}
