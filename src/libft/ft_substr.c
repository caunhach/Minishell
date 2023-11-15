/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:58:59 by wamonvor          #+#    #+#             */
/*   Updated: 2023/02/27 16:50:37 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	i = ft_strlen(&s[start]);
	if (len > i)
		j = i + 1;
	else
		j = len + 1;
	str = (char *)malloc(j * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], j);
	return (str);
}

/*
some on str = (char *)malloc(j * sizeof(char));
	if (str == 0)
		return (0);
but document refer to return null ??
		str = (char *)malloc(j * sizeof(char));
	if (str == NULL)
		return (NULL);
char const *s is declares a pointer variable named s 
that points to a constant string of characters. 
The const keyword indicates that the characters in the string pointed to by s
cannot be modified through s.

Note that the pointer s itself can be modified to point to a different string

The function is creat a substring from the string s.
The substring begin at index of start and copy for len size in substring.
Return the substring creat from s, or NULL if memory not allocated.
*/
