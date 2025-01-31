/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:35 by schiper           #+#    #+#             */
/*   Updated: 2024/11/05 12:50:43 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned const char	*str1 = s1;
	unsigned const char	*str2 = s2;

	while (n > 0)
	{
		if (*str1 != *str2)
			return ((*str1) - (*str2));
		str1++;
		str2++;
		n--;
	}
	return (0);
}
