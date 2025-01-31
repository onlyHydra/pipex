/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:19 by schiper           #+#    #+#             */
/*   Updated: 2024/11/04 19:28:21 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned long len)
{
	unsigned long	j;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		j = 0;
		while (len - j > 0 && *(big + j) == *(little + j))
		{
			if (!*(little + j + 1))
				return ((char *)big);
			j++;
		}
		big++;
		len--;
	}
	return ((void *)0);
}
