/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:14:29 by schiper           #+#    #+#             */
/*   Updated: 2024/11/08 19:26:10 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;
	t_list	*copy2;

	if (lst == NULL || del == NULL)
		return ;
	copy = *lst;
	while (copy != NULL)
	{
		copy2 = copy->next;
		del(copy->content);
		free(copy);
		copy = copy2;
	}
	*lst = NULL;
}
