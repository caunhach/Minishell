/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:06:33 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/29 13:06:40 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
if (!f)
		return ;
is same if(f == null) 
and return null ; 
like a standard function void list_for_each(void *list, void (*callback)(void *))
The function ft_lstiter pass the nodes start from lst
in function pointed by agrument f one by one.
*/
