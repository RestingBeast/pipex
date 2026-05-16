/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:20:25 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/05/16 11:20:26 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_delimiter(char *line, char *delimiter)
{
	size_t	len;

	len = ft_strlen(delimiter);
	if (len != ft_strlen(line) - 1)
		return (0);
	return (ft_strncmp(line, delimiter, len) == 0);
}

int	ft_streq(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, len) == 0);
}

void	spawn_child(int read, int *fds, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		early_exit(NULL);
	if (pid == 0)
	{
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
	{
		close(read);
		close(fds[1]);
	}
}

int	exe_cmd(int prev_fd, char *cmd, char **envp)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (early_exit(NULL), 0);
	spawn_child(prev_fd, fds, cmd, envp);
	return (fds[0]);
}
