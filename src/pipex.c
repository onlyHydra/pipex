/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:01:43 by hydra             #+#    #+#             */
/*   Updated: 2025/01/27 22:07:49 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **encp, int *fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
	{
		perror("Error");
		exit(1);
	}
	dup2(file_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], encp);
}

void	parent(char **argv, char **encp, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
	{
		perror("Error");
		exit(1);
	}
	dup2(file_out, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execute(argv[3], encp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			exit(1);
		}
		if (pid == 0)
			child(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent(argv, envp, fd);
	}
	return (0);
}
