/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:57:18 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/06 13:07:32 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error2(char *message, int exitcode)
{
	ft_fprintf(2, "pipex: %s\n", message);
	free(message);
	exit(exitcode);
}

void	error(char *message, int exitcode)
{
	ft_fprintf(2, "%s: %s\n", message, strerror(exitcode));
	exit(exitcode);
}

char	*find_path(char *command, char **envp)
{
	char	**paths;
	char	*cmdpath;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i += 1;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		cmdpath = ft_strjoin(paths[i], command);
		if (access(cmdpath, F_OK) == 0)
			break ;
		free(cmdpath);
		cmdpath = NULL;
	}
	i = -1;
	while (paths[++i] != NULL)
		free(paths[i]);
	return (free(paths), free(command), cmdpath);
}

void	cfg_cmdpath(char ***cmdargv, char **cmdpath, char *raw, char *envp[])
{
	if (ft_strlen(raw) == 0)
		error2(ft_strjoin("", ": command not found"), 127);
	if ((ft_strncmp(raw, "./", 2)) == 0)
	{
		*cmdargv = ft_split(raw + 2, ' ');
		*cmdpath = *(cmdargv[0]);
		return ;
	}
	*cmdargv = ft_split(raw, ' ');
	if (ft_strchr(*cmdargv[0], '/'))
		*cmdpath = *(cmdargv[0]);
	else
		*cmdpath = find_path(ft_strjoin("/", *cmdargv[0]), envp);
	if (access(*cmdpath, F_OK) != 0)
		error2(ft_strjoin(*cmdargv[0], ": command not found"), 127);
}

void	open_files(char **argv, int argc, int *infile, int *outfile)
{
	if (strncmp(argv[1], "here_doc", 8) == 0)
	{
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*outfile == -1)
		{
			ft_fprintf(2, "pipex: %s: %s\n", strerror(errno), argv[argc - 1]);
			*outfile = open("/dev/null", O_WRONLY, 0644);
		}
	}
	else
	{
		*infile = open(argv[1], O_RDONLY, 0644);
		if (*infile == -1)
		{
			ft_fprintf(2, "pipex: %s: %s\n", strerror(errno), argv[1]);
			*infile = open("/dev/null", O_RDONLY, 0644);
		}
		dup2(*infile, STDIN_FILENO);
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*outfile == -1)
		{
			ft_fprintf(2, "pipex: %s: %s\n", strerror(errno), argv[argc - 1]);
			*outfile = open("/dev/null", O_WRONLY, 0644);
		}
	}
}
