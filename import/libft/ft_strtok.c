/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:52:17 by schiper           #+#    #+#             */
/*   Updated: 2025/02/04 01:10:43 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;

	if (str == NULL)
		str = *saveptr;
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}
	token = str;
	str = ft_strpbrk(token, delim);
	if (str == NULL)
	{
		*saveptr = token + ft_strlen(token);
	}
	else
	{
		*str = '\0';
		*saveptr = str + 1;
	}
	return (token);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saveptr;

	return (ft_strtok_r(str, delim, &saveptr));
}
