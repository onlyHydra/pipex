/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:24 by schiper           #+#    #+#             */
/*   Updated: 2024/11/08 19:24:57 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (new == NULL)
		return ;
	copy = *lst;
	if (copy == NULL)
	{
		*lst = new;
		return ;
	}
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = new;
}
