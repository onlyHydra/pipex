/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:46:50 by schiper           #+#    #+#             */
/*   Updated: 2025/02/06 03:17:01 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n > 0)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
