/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:31:05 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:37:51 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s || len == 0)
		return (d);
	if (d > s && s + len > d)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
		return (ft_memcpy(d, s, len));
	return (d);
}
/*
The function is copy len bytes from the string src to string dst.
The two strings may overlap, the copy is always done in a non-destructive manner.
and then Returns the original value of dst.
*/
