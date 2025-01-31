/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:02:37 by schiper           #+#    #+#             */
/*   Updated: 2024/11/05 11:37:29 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long	src_size;
	unsigned long	dst_size;
	unsigned long	i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = 0;
	if (size <= dst_size)
	{
		return (size + src_size);
	}
	while (src[i] && (dst_size + i) < (size - 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
