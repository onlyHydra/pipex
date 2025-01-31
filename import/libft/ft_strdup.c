/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:11:32 by schiper           #+#    #+#             */
/*   Updated: 2024/11/06 22:14:58 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	j;
	unsigned int	i;
	char			*a;

	j = ft_strlen(s);
	i = 0;
	a = malloc(((j) * sizeof(char)) + 1);
	if (a == (void *)0)
	{
		return ((void *)0);
	}
	while (i < j)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
