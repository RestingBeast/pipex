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

static void	free_double_ptr(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

static char	**get_env_path(char **envp)
{
	char	**path;
	char	*tmp;

	path = NULL;
	if (envp == NULL || *envp == NULL)
		return (ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", ':'));
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			path = ft_split(*envp, ':');
		envp++;
	}
	if (!path)
		return (ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", ':'));
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
			return (free(filename), free_double_ptr(path), res);
		free(res);
		i++;
	}
	free(filename);
	free_double_ptr(path);
	return (NULL);
}

void	log_error(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	parse_cmd_and_execute(char *cmd, char **envp)
{
	char	**argv;
	char	*filename;

	if (ft_strlen(cmd) == 0)
	{
		log_error("''");
		exit(127);
	}
	argv = ft_split(cmd, ' ');
	filename = find_executable(argv[0], envp);
	if (!filename)
	{
		log_error(argv[0]);
		free_double_ptr(argv);
		exit(127);
	}
	if (execve(filename, argv, envp) == -1)
	{
		free(filename);
		free_double_ptr(argv);
		early_exit(NULL);
	}
}
