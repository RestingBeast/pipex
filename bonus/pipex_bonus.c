/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:19:17 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/05/16 11:19:18 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_here_doc(char *delimiter)
{
	char	*line;
	int		fd;

	fd = open(HERE_DOC, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1);
	line = get_next_line(0);
	while (line != NULL && !(is_delimiter(line, delimiter)))
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd);
	fd = open(HERE_DOC, O_RDONLY);
	return (fd);
}

static int	exe_first_cmd(char *infile, char *cmd, char **envp)
{
	int	fds[2];

	if (pipe(fds) == -1)
		early_exit(NULL);
	return (spawn_first_child(infile, fds, cmd, envp));
}

static void	start_pipex(int argc, char **argv, char **envp)
{
	int			prev_read;
	int			option;
	int			pid;
	int			i;
	t_outfile	o;

	option = ft_streq(argv[1], HERE_DOC);
	if (option == 1)
		prev_read = get_here_doc(argv[2]);
	else
		prev_read = exe_first_cmd(argv[1], argv[2], envp);
	i = 2;
	while (++i < argc - 2)
		prev_read = exe_cmd(prev_read, argv[i], envp);
	o.filename = argv[argc - 1];
	if (option == 1)
		o.flags = O_RDWR | O_CREAT | O_APPEND;
	else
		o.flags = O_RDWR | O_CREAT | O_TRUNC;
	pid = spawn_last_child(prev_read, &o, argv[i], envp);
	if (option == 1)
		unlink(HERE_DOC);
	kill_zombies(i - option, pid);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (0);
	start_pipex(argc, argv, envp);
	return (0);
}
