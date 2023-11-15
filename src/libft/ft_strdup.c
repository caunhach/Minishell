/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:49:57 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 13:01:21 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s, len + 1);
	return (p);
}
/*
The function is allocates sufficient memory for copy of the strings s1,
does the copy,
and returns a pointer to it.
The pointer may be used as an argument to the function free.

In summary, strdup is used to create a duplicate of a null-terminated string, 
while memcpy is used to copy a specified number of bytes from one 
memory location to another.
*/
