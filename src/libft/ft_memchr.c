/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:25:54 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:40:10 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (len > 0)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
		len--;
	}
	return (NULL);
}
/*
The function is find location the first occurence of values c in string s,
search in no more than len characteres of in string s.
Return a pointer to the byte located c.
*/
