/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:17:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/24 22:18:08 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include "ft_printf.h"
# include "get_next_line.h"

/* Mandatory Part */
// utils.c
void	early_exit(char *filename);
void	spawn_child(int read, int *fds, char *cmd, char **envp);
void	spawn_last_child(int read, int write, char *cmd, char **envp);
int		exe_cmd(int prev_fd, char *cmd, char **envp);
void	kill_zombies(int count);
// parser.c
void	parse_cmd_and_execute(char *cmd, char **envp);

/* Bonus Part */
# define HERE_DOC "here_doc"
int		is_delimiter(char *line, char *delimiter);
int		ft_streq(char *s1, char *s2);

#endif
