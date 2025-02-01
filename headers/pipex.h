/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:05:31 by hydra             #+#    #+#             */
/*   Updated: 2025/02/01 16:15:19 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PIPEX_H)
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_file
{
	int		file_fd;
	int		file_in;
	int		file_out;
	char	*filename;
}			t_file;

# define BUFFER_SIZE 100000
/* Mandatory functions */
int			get_next_line(char **line);
void		execute(char *argv, char **envp);

/* Bonus functions */
int			open_file(char *argv, int i);
void		usage(void);
void		error_handler(char *err, char *message, int exit_code);

#endif // PIPEX_H
