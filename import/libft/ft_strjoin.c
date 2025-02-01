/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:47:34 by schiper           #+#    #+#             */
/*   Updated: 2025/02/01 13:22:16 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	str_len;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(str_len);
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(str, s1, str_len);
	if (ft_strlen(s1) > 0 && s1 != NULL)
		ft_strlcpy(str + ft_strlen(s1), s2, str_len);
	else
		ft_strlcpy(str, s2, str_len);
	str[str_len - 1] = '\0';
	return (str);
}
