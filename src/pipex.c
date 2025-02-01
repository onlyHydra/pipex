/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:01:43 by hydra             #+#    #+#             */
/*   Updated: 2025/02/01 16:43:28 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <stdio.h>

void	child(char *argv, char **encp, t_file file)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_handler("Error", "pipe", 1);
	pid = fork();
	if (pid < 0)
		error_handler("Error", "fork", 1);
	if (pid == 0)
	{
		if (file.file_fd < 0)
			error_handler(file.filename, ": No such file or directory\n", 1);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, encp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	read_console(char *argv)
{
	char	*line;

	while (get_next_line(&line) > 0)
	{
		if (ft_strncmp(line, argv, ft_strlen(argv)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(1, line, strlen(line));
		free(line);
	}
}

void	console_input(char *argv)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_handler("Error", "pipe", 1);
	pid = fork();
	if (pid < 0)
		error_handler("Error", "fork", 1);
	if (pid == 0)
	{
		close(fd[0]);
		read_console(argv);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	launch_process(char **argv, char **envp, int argc, t_file file)
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
	int		i;
	t_file	file;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			file.file_out = open_file(argv[argc - 1], 0);
			console_input(argv[2]);
		}
		else
		{
			i = 2;
			file.file_out = open_file(argv[argc - 1], 1);
			file.file_in = open_file(argv[1], 2);
			dup2(file.file_in, STDIN_FILENO);
			file.file_fd = file.file_in;
			file.filename = argv[1];
		}
		launch_process(argv + i, envp, argc - i, file);
		dup2(file.file_out, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	usage();
}
