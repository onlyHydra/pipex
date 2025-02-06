/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:09:24 by hydra             #+#    #+#             */
/*   Updated: 2025/02/06 03:32:14 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> ... <file>\n", 1);
	exit(EXIT_FAILURE);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file < 0)
		perror(argv);
	return (file);
}

void	error_handler(char *message, int exit_code)
{
	perror(message);
	exit(exit_code);
}

int	get_next_line(char **line)
{
	char	*buffer;
	char	data;
	int		ret;
	int		i;

	buffer = malloc(BUFFER_SIZE);
	data = 0;
	if (!buffer)
		return (-1);
	ret = read(0, &data, 1);
	i = 0;
	if (ret == -1)
	{
		free(buffer);
		return (-1);
	}
	while (ret > 0 && data != '\n' && data != '\0')
	{
		buffer[i++] = data;
		ret += read(0, &data, 1);
	}
	buffer[i] = '\0';
	*line = buffer;
	return (ret);
}
