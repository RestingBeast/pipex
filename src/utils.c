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

void	free_argv(char **argv)
{
	int	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

void	debug_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		ft_printf("argv[%d]: %s\n", (i + 1), argv[i]);
		i++;
	}
}

char	*find_executable(char *cmd, char **envp)
{
	char	**path;
	char	*res;
	char	*tmp;
	int		i;

	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			path = ft_split(*envp, ':');
		envp++;
	}
	tmp = path[0];
	path[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (path[i] != NULL)
	{
		res = ft_strjoin(path[i], cmd);
		ft_printf("%s\n", res);
		free(res);
		i++;
	}
	free(cmd);
	free_argv(path);
	return (NULL);
}

int	parse_cmd_and_exe(char *cmd, char **envp)
{
	char	**argv;

	argv = ft_split(cmd, ' ');
	// debug_argv(argv + 1);
	envp++;
	find_executable(cmd, envp);
	free_argv(argv);
	return (0);
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
	parse_cmd_and_exe(cmd, envp);
	return ;
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
		char *argv[] = {NULL};
		if (execve(cmd, argv, envp) == -1)
			_exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
	}
}
