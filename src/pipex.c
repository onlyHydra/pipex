/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:01:43 by hydra             #+#    #+#             */
/*   Updated: 2025/02/06 03:43:54 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static void	child(char *argv, char **encp, t_file file)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_handler("pipex", 1);
	pid = fork();
	if (pid < 0)
		error_handler("pipex", 1);
	if (pid == 0)
	{
		if (file.file_fd < 0)
			exit(1);
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_handler("pipex", 1);
		execute(argv, encp);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		close(fd[0]);
	}
}

static void	launch_process(char **argv, char **envp, int argc, t_file file)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		child(argv[i], envp, file);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_file	file;

	if (argc == 5)
	{
		file.file_out = open_file(argv[argc - 1], 1);
		file.file_fd = open_file(argv[1], 2);
		dup2(file.file_fd, STDIN_FILENO);
		file.filename = argv[1];
		launch_process(argv + 2, envp, argc - 2, file);
		dup2(file.file_out, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
	}
}
