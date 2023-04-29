/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/29 16:20:39 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	child(char *file, char *rawcmd, char **envp, int fd[2])
{
	char	**cmdargv;
	char	*cmdpath;
	int		input_fd;

	cmdargv = ft_split(rawcmd, ' ');
	if (ft_strncmp(cmdargv[0], "./", 2) == 0)
	{
		cmdargv[0] += 2;
		cmdpath = cmdargv[0];
	}
	else if (ft_strchr(cmdargv[0], '/'))
		cmdpath = cmdargv[0];
	else
		cmdpath = find_path(ft_strjoin("/", cmdargv[0]), envp);
	if (access(cmdpath, X_OK) != 0)
		error("pipex", 13);
	input_fd = open(file, O_RDONLY, 0644);
	if (input_fd == -1)
		error("pipex: input", errno);
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(cmdpath, cmdargv, envp) == -1)
		error("pipex", errno);
}

void	parent(char *file, char *rawcmd, char **envp, int fd[2])
{
	char	**cmdargv;
	char	*cmdpath;
	int		output_fd;

	cmdargv = ft_split(rawcmd, ' ');
	if (ft_strncmp(cmdargv[0], "./", 2) == 0)
	{
		cmdargv[0] += 2;
		cmdpath = cmdargv[0];
	}
	else if (ft_strchr(cmdargv[0], '/'))
		cmdpath = cmdargv[0];
	else
		cmdpath = find_path(ft_strjoin("/", cmdargv[0]), envp);
	output_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd == -1)
		error("pipex: output", errno);
	dup2(fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(fd[1]);
	if (execve(cmdpath, cmdargv, envp) == -1)
		error("pipex", errno);
}

int	main(int argc, char **argv, char *envp[])
{
	int		fd[2];
	pid_t	process;

	if (argc == 5)
	{
		if (envp == NULL || envp[0] == NULL)
			error("pipex", 11);
		if (pipe(fd) == -1)
			error("pipex", errno);
		process = fork();
		if (process == -1)
			error("pipex", errno);
		if (process == 0)
			child(argv[1], argv[2], envp, fd);
		parent(argv[4], argv[3], envp, fd);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
