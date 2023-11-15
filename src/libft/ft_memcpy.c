/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:26:19 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:36:46 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

/*
The function is copy n bytes from memory area src to memory area dst.
and then Return the original value of dst.
*/
