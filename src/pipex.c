/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/23 15:31:08 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char *file, char *rawcmd, char **envp, int fd[2])
{
	char	**cmdargv;
	char	*cmdpath;
	int		input_fd;

	ft_printf("DEBUG: Entered child.\n");
	cmdargv = ft_split(rawcmd, ' ');
	cmdpath = find_path(ft_strjoin("/", cmdargv[0]), envp);
	input_fd = open(file, O_RDONLY, 0644);
	if (input_fd == -1)
		error("Failed to open input file.");
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(cmdpath, cmdargv, envp) == -1)
		error("Failed to execute child's command.");
}

void	parent(char *file, char *rawcmd, char **envp, int fd[2])
{
	char	**cmdargv;
	char	*cmdpath;
	int		output_fd;

	ft_printf("DEBUG: Entered parent.\n");
	cmdargv = ft_split(rawcmd, ' ');
	cmdpath = find_path(ft_strjoin("/", cmdargv[0]), envp);
	output_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd == -1)
		error("Failed to open output file.");
	dup2(fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(fd[1]);
	if (execve(cmdpath, cmdargv, envp) == -1)
		error("Failed to execute parent's command.");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	process;

	if (argc == 5)
	{
		status = 0;
		if (pipe(fd) == -1)
			error("Failed to initiate pipe.");
		process = fork();
		if (process == -1)
			error("Failed to create child process.");
		if (process == 0)
			child(argv[1], argv[2], envp, fd);
		waitpid(process, &status, 0);
		if (status != 0)
			error("Child process failed.");
		parent(argv[4], argv[3], envp, fd);
	}
	return (0);
}
