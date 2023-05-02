/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/02 15:28:18 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	children(char *rawcmd, char **envp)
{
	pid_t	process;
	char	**cmdargv;
	char	*cmdpath;
	int		fd[2];

	if (pipe(fd) == -1)
		error("pipex", errno);
	process = fork();
	if (process == -1)
		error("pipex", errno);
	if (process == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		config_cmdpath(&cmdargv, &cmdpath, rawcmd, envp);
		if (access(cmdpath, F_OK) != 0)
			error2(ft_strjoin(cmdargv[0], ": command not found"), 127);
		if (access(cmdpath, X_OK) != 0)
			error2(ft_strjoin(cmdargv[0], ": permission denied"), errno);
		execve(cmdpath, cmdargv, envp);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(process, NULL, 0);
}

void	last_cmd(char *rawcmd, char **envp, int outfd)
{
	pid_t	process;
	char	**cmdargv;
	char	*cmdpath;

	process = fork();
	if (process == -1)
		error("pipex", errno);
	if (process == 0)
	{
		dup2(outfd, STDOUT_FILENO);
		close(outfd);
		config_cmdpath(&cmdargv, &cmdpath, rawcmd, envp);
		if (access(cmdpath, F_OK) != 0)
			error2(ft_strjoin(cmdargv[0], ": command not found"), 127);
		if (access(cmdpath, X_OK) != 0)
			error2(ft_strjoin(cmdargv[0], ": permission denied"), errno);
		execve(cmdpath, cmdargv, envp);
	}
	else
	{
		close(STDIN_FILENO);
		close(outfd);
		waitpid(process, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	cmdi;

	if (argc >= 5)
	{
		cmdi = 2;
		infile = open(argv[1], O_RDONLY, 0644);
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(infile, STDIN_FILENO);
		while (cmdi < argc - 2)
			children(argv[cmdi++], envp);
		last_cmd(argv[argc - 2], envp, outfile);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
