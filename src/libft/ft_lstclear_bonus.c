/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:05:07 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/29 13:05:10 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*node;

	if (!del || !lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		node = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = node;
	}
	*lst = NULL;
}

/*
The function ft_lstclear pass the node pointed by lst and the nodes after
to the function pointed by del, and free the memory of the nodes.
*/
