/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:49:09 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:28:47 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
		len--;
	}
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}
/*
The function is locates the first occurence of c
in the string pointed to by s, this included the null character.
then Return a pointer to the located character and null when have not match

result is same memchr
strchr expects the input buffer to be a null-terminated string,
 while memchr works on any buffer of bytes, including null bytes.

The strchr function stops searching when it reaches a null byte ('\0'), 
indicating the end of the string. On the other hand, 
memchr takes an explicit length parameter to specify 
the number of bytes to search within the buffer.
*/
