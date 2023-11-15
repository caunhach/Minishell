/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:53:55 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/28 13:16:55 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	i = 0;
	while ((src[i] != '\0') && (i != size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lensrc);
}
/*
memcpy is a general-purpose function that is used to copy a specified 
number of bytes from one memory location to another. It is not 
specific to null-terminated strings, and does not guarantee that
 the destination buffer will be null-terminated.

strlcpy, on the other hand, is specifically designed to copy 
null-terminated strings, and ensures that the destination buffer
 is null-terminated. It takes a destination buffer,
 a source buffer, and the size of the destination buffer as arguments.
used to copy a string from a source buffer to a destination buffer,
the function is copy up to dstsize -1 characteres
from string src to dst.
NULL-terminating the result if dstsize is not 0.
Returns the (ft_strlen) total lenght of the string src to create.
*/
