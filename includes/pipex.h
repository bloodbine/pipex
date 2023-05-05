/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:06:05 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:37 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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

#endif