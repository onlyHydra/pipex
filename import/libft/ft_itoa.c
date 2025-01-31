/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:48:57 by schiper           #+#    #+#             */
/*   Updated: 2024/11/06 22:12:44 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_number_len(int nb)
{
	unsigned long	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long		number;
	unsigned long	size;

	number = (long long)n;
	size = ft_number_len(n);
	if (n < 0)
	{
		size++;
		number = -number;
	}
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[size - 1] = '0';
	str[size] = '\0';
	while (number)
	{
		str[--size] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
