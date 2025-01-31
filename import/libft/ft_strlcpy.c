/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:47:51 by schiper           #+#    #+#             */
/*   Updated: 2024/11/04 19:52:53 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long n)
{
	unsigned int	size;

	size = 0;
	if (n >= 1)
	{
		while (src[size] != '\0' && size < n - 1)
		{
			dst[size] = src[size];
			size++;
		}
		dst[size] = '\0';
	}
	return (ft_strlen(src));
}
