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

void	spawn_child(int read, int write, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (early_exit());
	if (pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
			_exit(EXIT_FAILURE);
		if (dup2(write, STDOUT_FILENO) == -1)
			_exit(EXIT_FAILURE);
		close(read);
		close(write);
		parse_cmd_and_execute(cmd, envp);
	}
	else
		close(write);
}

void	normal_case(int prev_read, char *cmd, char **envp)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (early_exit());
	spawn_child(prev_read, fd[1], cmd, envp);
}

void	special_case(char *cmd, char **envp)
{
	spawn_child(prev_read, outfile, cmd, envp);
}
