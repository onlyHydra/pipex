/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:30 by schiper           #+#    #+#             */
/*   Updated: 2024/11/09 16:02:29 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long nmemb, unsigned long size)
{
	unsigned long	i;
	void			*arr;

	if (size > 0 && nmemb > (18446744073709551615ULL / size))
		return (NULL);
	i = nmemb * size;
	arr = malloc(i);
	if (arr == (void *)0)
		return ((void *)0);
	ft_memset(arr, 0, i);
	return (arr);
}
