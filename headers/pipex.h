/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:05:31 by hydra             #+#    #+#             */
/*   Updated: 2025/01/31 17:51:11 by schiper          ###   ########.fr       */
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

# define BUFFER_SIZE 100000
/* Mandatory functions */
int		get_next_line(char **line);
void	execute(char *argv, char **envp);

/* Bonus functions */
int		open_file(char *argv, int i);
void	usage(void);
void	error_handler(void);
#endif // PIPEX_H
