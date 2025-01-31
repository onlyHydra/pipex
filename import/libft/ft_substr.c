/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:44:04 by schiper           #+#    #+#             */
/*   Updated: 2024/11/05 14:22:59 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*str;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		start = 0;
		len = 0;
	}
	if (len > slen - start)
		len = slen - start;
	slen = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (slen < len)
	{
		str[slen] = s[start + slen];
		slen++;
	}
	str[slen] = '\0';
	return (str);
}
