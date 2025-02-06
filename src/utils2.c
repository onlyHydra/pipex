/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:15:27 by schiper           #+#    #+#             */
/*   Updated: 2025/02/06 04:07:21 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static void	free_split(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

static char	*envp_get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	free_split(paths);
	return ((void *)0);
}

static char	**trim_cmd(char **cmd)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (cmd[i])
	{
		trimmed = ft_strtrim(cmd[i], "'");
		if (trimmed)
		{
			free(cmd[i]);
			cmd[i] = trimmed;
		}
		else
		{
			while (i > 0)
				free(cmd[--i]);
			free(cmd);
			return (NULL);
		}
		i++;
	}
	return (cmd);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (ft_strnstr(argv, "awk", ft_strlen(argv)) != 0)
	{
		cmd = awk_split(argv, ' ');
		cmd = trim_cmd(cmd);
	}
	else
		cmd = ft_split(argv, ' ');
	path = envp_get_path(cmd[0], envp);
	if (ft_strncmp(cmd[0], "", 1) != 0 && !path)
	{
		free_split(cmd);
		free(path);
		error_handler("pipex: command not found b", 127);
	}
	if (ft_strncmp(cmd[0], "", 1) != 0 && execve(path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(path);
		error_handler("pipex", 127);
	}
	free_split(cmd);
	free(path);
}
