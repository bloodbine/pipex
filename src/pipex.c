/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:54:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/19 16:13:11 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **argv, char **envp, int *fd)
{
	int	infd;

	
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	forkid;
	int		fd[2];

	envp = NULL;
	argv = NULL;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (EXIT_FAILURE);
		forkid = fork();
		if (forkid == -1)
			return (EXIT_FAILURE);
		if (forkid == 0)
			child();
		waitpid(forkid, NULL, 0);
		ft_printf("test %d\n", forkid);
	}
	else
	{
		error();
		return (EXIT_FAILURE);
	}
}
