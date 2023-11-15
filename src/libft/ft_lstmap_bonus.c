/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:07:27 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/29 13:07:30 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
/*
lst: pointer to the first element of the list.
f: pointer to the function to be applied to each element of the list.
del: pointer to the function used to delete the content of an element 
if necessary. 
If del is NULL, the content of the list elements is not freed.

that applies a function to each node in a linked list 
and returns a new linked list containing the modified nodes. 
It takes two arguments: a pointer to the first node of a linked list,
and a function pointer that takes a void pointer as an argument and 
returns a void pointer.
*/
