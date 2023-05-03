/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/03 15:44:58 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	here_doc_loop(int tempfd, int filefd, char *delim)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(filefd);
		if (line == NULL || ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			break ;
		ft_fprintf(tempfd, "%s", line);
		free(line);
	}
	if (line != NULL)
		free(line);
}

void	here_doc(char *file, char *delim)
{
	int		filefd;
	int		tempfd;

	filefd = open(file, O_RDONLY, 0644);
	if (filefd == -1)
		error("pipex: input", errno);
	tempfd = open(".heredoc0.XXXXXX", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(filefd, STDIN_FILENO);
	here_doc_loop(tempfd, filefd, delim);
	close(filefd);
	close(tempfd);
	tempfd = open(".heredoc0.XXXXXX", O_RDONLY, 0644);
	dup2(tempfd, STDIN_FILENO);
	unlink(".heredoc0.XXXXXX");
}

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
}

void	last_cmd(char *rawcmd, char **envp, int outfd)
{
	pid_t	process;
	char	**cmdargv;
	char	*cmdpath;
	int		status;

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
	close(STDIN_FILENO);
	close(outfd);
	waitpid(process, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	cmdi;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			cmdi = 4;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			here_doc(argv[2], argv[3]);
		}
		else
		{
			cmdi = 2;
			infile = open(argv[1], O_RDONLY, 0644);
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(infile, STDIN_FILENO);
		}
		while (cmdi < argc - 2)
			children(argv[cmdi++], envp);
		last_cmd(argv[argc - 2], envp, outfile);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
