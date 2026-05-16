/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:33:39 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/05/16 13:53:49 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	early_exit(char *filename)
{
	if (filename)
		ft_printf("pipex: %s: %s\n", filename, strerror(errno));
	else
		perror("pipex");
	exit(EXIT_FAILURE);
}

int	spawn_first_child(char *infile, int *fds, char *cmd, char **envp)
{
	pid_t	pid;
	int		read;

	pid = fork();
	if (pid == -1)
		early_exit(NULL);
	if (pid == 0)
	{
		read = open(infile, O_RDONLY);
		if (read == -1)
			early_exit(infile);
		if (dup2(read, STDIN_FILENO) == -1)
			early_exit(NULL);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			early_exit(NULL);
		close(read);
		close(fds[0]);
		close(fds[1]);
		parse_cmd_and_execute(cmd, envp);
	}
	else
		close(fds[1]);
	return (fds[0]);
}

int	spawn_last_child(int read, t_outfile *o, char *cmd, char **envp)
{
	pid_t	pid;
	int		write;

	pid = fork();
	if (pid == -1)
		early_exit(NULL);
	if (pid == 0)
	{
		write = open(o->filename, o->flags, 0644);
		if (write == -1)
			early_exit(o->filename);
		if (dup2(read, STDIN_FILENO) == -1)
			early_exit(NULL);
		if (dup2(write, STDOUT_FILENO) == -1)
			early_exit(NULL);
		close(read);
		close(write);
		parse_cmd_and_execute(cmd, envp);
	}
	else
		close(read);
	return (pid);
}

void	kill_zombies(int count, int last_pid)
{
	int	status;
	int	exit_status;

	waitpid(last_pid, &exit_status, 0);
	while (--count > 1)
		waitpid(-1, &status, 0);
	exit((exit_status >> 8) & 0xff);
}
