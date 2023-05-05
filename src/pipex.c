/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/05 12:08:54 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc_loop(int tempfd, char *delim)
{
	char	*line;

	line = NULL;
	while (1)
	{
		ft_fprintf(STDIN_FILENO, "> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			ft_fprintf(STDIN_FILENO, "\n");
			return ;
		}
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			break ;
		ft_fprintf(tempfd, "%s", line);
		free(line);
	}
	if (line != NULL)
		free(line);
}

void	here_doc(char *delim)
{
	int		tempfd;

	tempfd = open(".heredoc0.XXXXXX", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	here_doc_loop(tempfd, delim);
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
		cfg_cmdpath(&cmdargv, &cmdpath, rawcmd, envp);
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
		cfg_cmdpath(&cmdargv, &cmdpath, rawcmd, envp);
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
			cmdi = 3;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			here_doc(argv[2]);
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
