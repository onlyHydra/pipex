/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:01:43 by hydra             #+#    #+#             */
/*   Updated: 2025/02/04 15:28:07 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

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
        fd[1] = STDOUT_FILENO;
        ft_putendl_fd("We are in the parent", STDOUT_FILENO);
		if(dup2(fd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
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
		write(1, line, ft_strlen(line));
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



	if (argc == 5)
	{
		i = 2;
		file.file_out = open_file(argv[argc - 1], 1);
		file.file_fd = open_file(argv[1], 2);
		dup2(file.file_fd, STDIN_FILENO);
		file.filename = argv[1];
		launch_process(argv + i, envp, argc - i, file);
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
