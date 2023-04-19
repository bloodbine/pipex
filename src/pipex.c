/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/19 17:44:52 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **argv, char **envp, int (*fd)[2])
{
	int	infd;

	infd = open(argv[1], O_RDONLY, 0777);
	if (infd == -1)
		error("Failed to open infile");
	dup2(*fd[1], STDOUT_FILENO);
	dup2(infd, STDIN_FILENO);
	close(*fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	fork_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (EXIT_FAILURE);
		fork_id = fork();
		if (fork_id == -1)
			return (EXIT_FAILURE);
		if (fork_id == 0)
			child(argv, envp, &fd);
		waitpid(fork_id, NULL, 0);
		ft_printf("test %d\n", fork_id);
	}
	else
		error("Invalid arguments");
	return (0);
}
