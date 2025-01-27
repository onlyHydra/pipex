/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:05:31 by hydra             #+#    #+#             */
/*   Updated: 2025/01/27 22:10:31 by hydra            ###   ########.fr       */
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

/* Mandatory functions */
void	error(void);
char	*find_path(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);

/* Bonus functions */
int		open_file(char *argv, int i);
void	usage(void);

#endif // PIPEX_H
