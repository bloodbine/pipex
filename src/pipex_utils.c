/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:57:18 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/23 14:03:58 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *message)
{
	write(2, "Error\n", 7);
	write(2, message, ft_strlen(message) + 1);
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}

char	*find_path(char *command, char **envp)
{
	char	**paths;
	char	*cmdpath;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH", 4 != 0))
		i += 1;
	if (envp[i] == NULL)
		error("'PATH' environment variable not found.");
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		cmdpath = ft_strjoin(paths[i], command);
		if (access(cmdpath, F_OK | X_OK) == 0)
			break ;
		free(cmdpath);
		cmdpath = NULL;
	}
	if (paths[i] == NULL || cmdpath == NULL)
		error("Binary not found");
	i = -1;
	while (paths[++i] != NULL)
		free(paths[i]);
	return (free(paths), free(command), cmdpath);
}
