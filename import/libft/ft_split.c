/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:52:00 by schiper           #+#    #+#             */
/*   Updated: 2024/11/06 21:45:32 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_count(char const *s, char c)
{
	unsigned long	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

int	ft_size(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

void	ft_free_array(char **arr, int size)
{
	while (size >= 0)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	arr = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		arr[j] = ft_substr(s, i, ft_size(s, c, i));
		if (!arr[j])
		{
			ft_free_array(arr, j);
			return (NULL);
		}
		i = i + ft_size(s, c, i);
		j++;
	}
	arr[j] = 0;
	return (arr);
}
