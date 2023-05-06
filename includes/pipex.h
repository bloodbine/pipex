/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:06:05 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/06 12:08:36 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

void	error(char *message, int exitcode);
void	error2(char *message, int exitcode);
char	*find_path(char *command, char **envp);
void	cfg_cmdpath(char ***cmdargv, char **cmdpath, char *raw, char *envp[]);
void	open_files(char **argv, int argc, int *infile, int *outfile);

#endif