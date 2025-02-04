/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:34:34 by schiper           #+#    #+#             */
/*   Updated: 2025/02/04 02:33:35 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static int	count_awk_tokens(const char *str, char c)
{
	int	count;
	int	in_braces;

	count = 0;
	in_braces = 0;
	while (*str)
	{
		if (*str == '{')
			in_braces = 1;
		else if (*str == '}')
			in_braces = 0;
		else if (*str == c && !in_braces)
			count++;
		str++;
	}
	return (count + 1);
}

static char	*copy_awk_token(const char *start, const char *end)
{
	char	*token;

	token = (char *)malloc(end - start + 1);
	if (!token)
		return (NULL);
	ft_strncpy(token, start, end - start);
	token[end - start] = '\0';
	return (token);
}

static void	add_awk_token(char **result, int *count, const char *start,
		const char *end)
{
	result[*count] = copy_awk_token(start, end);
	(*count)++;
}

static const char	*process_char(const char *str, char c, t_split_state *state,
		char **result)
{
	if (*str == '{')
	{
		state->in_braces = 1;
		if (!state->start)
			state->start = str;
	}
	else if (*str == '}')
		state->in_braces = 0;
	else if (*str == c && !state->in_braces)
	{
		if (state->start)
			add_awk_token(result, &state->count, state->start, str);
		state->start = NULL;
	}
	else if (!state->start)
		state->start = str;
	return (str + 1);
}

char	**awk_split(const char *str, char c)
{
	char			**result;
	t_split_state	state;

	state.start = NULL;
	state.count = 0;
	state.in_braces = 0;
	result = (char **)malloc(sizeof(char *) * (count_awk_tokens(str, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
		str = process_char(str, c, &state, result);
	if (state.start)
		add_awk_token(result, &state.count, state.start, str);
	result[state.count] = NULL;
	return (result);
}
