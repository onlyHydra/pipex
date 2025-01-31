/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:24:11 by schiper           #+#    #+#             */
/*   Updated: 2024/11/06 20:49:00 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	str = NULL;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1 != NULL && set != NULL)
	{
		len = ft_strlen(s1);
		i = 0;
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (len > i && s1[len - 1] && ft_strchr(set, s1[len - 1]))
			len--;
		str = (char *)malloc(sizeof(char) * (len - i + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[i], len - i + 1);
	}
	return (str);
}
