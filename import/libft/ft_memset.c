/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:58 by schiper           #+#    #+#             */
/*   Updated: 2024/11/06 22:15:28 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned char	*dest;
	unsigned char	value;
	unsigned long	i;

	i = 0;
	value = (unsigned char)c;
	dest = s;
	while (i < n)
	{
		dest[i] = value;
		i++;
	}
	return (s);
}
