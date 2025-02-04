/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:08:17 by schiper           #+#    #+#             */
/*   Updated: 2025/02/04 01:15:48 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *delim)
{
	char	*d;

	while (*str)
	{
		d = (char *)delim;
		while (*d)
		{
			if (*str == *d)
				return ((char *)str);
			d++;
		}
		str++;
	}
	return (NULL);
}
