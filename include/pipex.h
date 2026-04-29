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
# include "ft_printf.h"
# include "get_next_line.h"

// utils.c
void	early_exit(void);
void	free_double_ptr(char **argv);
void	spawn_child(int infile, int outfile, char *cmd, char **envp);
// parser.c
void	parse_cmd_and_execute(char *cmd, char **envp);

#endif
