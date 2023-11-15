/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:03:58 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/29 13:04:05 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

/*
The function have add a new node at the end of the list.
we must to declare structure before 
as i declare structure named s_list (in libft.h and include on header),
which is also given a typedef alias of t_list.

The s_list structure contains two members:

void *content: This member is a pointer to any type of data that
can be stored in the linked list node. The void type means that
the pointer has no specific data type associated with it, 
allowing it to point to data of any type.

struct s_list *next: This member is a pointer to the next node in
 the linked list. It is a pointer to another s_list structure
 , which is why it is defined as struct s_list *.

By using this structure, you can create a linked list in C.
Each node in the linked list will contain a content member that can 
store a pointer to any type of data, and a next member that points 
to the next node in the list. This allows you to create a list of arbitrary size,
where each element is connected to the next one via the next pointer.

The typedef statement at the end of the structure definition 
creates an alias t_list for the s_list structure. This allows you to refer to 
the structure as t_list instead of struct s_list, which can make the code easier 
to read and write.
*/
