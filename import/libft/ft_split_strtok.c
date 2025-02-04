/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_strtok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:42:42 by schiper           #+#    #+#             */
/*   Updated: 2025/02/04 00:58:00 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_tokens(const char *str)
{
	int		count;
	char	*input;
	char	*token;

	count = 0;
	input = ft_strdup(str);
	if (!input)
		return (0);
	token = ft_strtok(input, " ");
	while (token)
	{
		count++;
		token = ft_strtok(NULL, " ");
	}
	free(input);
	return (count);
}

static char	**allocate_result(int count)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (result);
}

static char	*copy_token(const char *token)
{
	char	*copy;

	copy = ft_strdup(token);
	if (!copy)
		return (NULL);
	return (copy);
}

static char	**split_tokens(const char *str, char **result)
{
	char	*input;
	char	*token;
	int		i;

	input = ft_strdup(str);
	i = 0;
	if (!input)
		return (free(result), NULL);
	token = ft_strtok(input, " ");
	while (token)
	{
		result[i] = copy_token(token);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			return (free(result), free(input), NULL);
		}
		i++;
		token = ft_strtok(NULL, " ");
	}
	result[i] = NULL;
	return (free(input), result);
}

char	**ft_split_strtok(const char *str)
{
	int		count;
	char	**result;

	count = count_tokens(str);
	result = allocate_result(count);
	if (!result)
		return (NULL);
	return (split_tokens(str, result));
}
