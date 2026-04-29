/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:27:20 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/29 21:27:29 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_env_path(char **envp)
{
	char	**path;
	char	*tmp;

	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			path = ft_split(*envp, ':');
		envp++;
	}
	tmp = path[0];
	path[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
	return (path);
}

static char	*find_executable(char *cmd, char **envp)
{
	char	**path;
	char	*filename;
	char	*res;
	int		i;

	i = 0;
	filename = ft_strjoin("/", cmd);
	path = get_env_path(envp);
	while (path[i] != NULL)
	{
		res = ft_strjoin(path[i], filename);
		if (access(res, F_OK | X_OK) == 0)
			return (free(cmd), free_double_ptr(path), res);
		free(res);
		i++;
	}
	free(cmd);
	free_double_ptr(path);
	return (NULL);
}

void	parse_cmd_and_execute(char *cmd, char **envp)
{
	char	**argv;
	char	*filename;

	argv = ft_split(cmd, ' ');
	filename = find_executable(argv[0], envp);
	if (!filename)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free(filename);
		free_double_ptr(argv);
		_exit(EXIT_FAILURE);
	}
	if (execve(filename, argv, envp) == -1)
	{
		free(filename);
		free_double_ptr(argv);
		perror("pipex");
		_exit(EXIT_FAILURE);
	}
}
