/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:26:05 by wamonvor          #+#    #+#             */
/*   Updated: 2023/02/18 14:26:07 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/*
The function ft_memcmp compare byte string s1 against byte string s2.
Both strings are assumed to be n bytes long.
Return zero if both are identical,
otherwise the differnce between the first two differing bytes.
Zero-lenght strings are identical.

you can declare new paramter on start fuction 
     unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;

	or you can cast parameter inloop like this
if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));


standard 
If s1 is less than s2, the function returns a negative integer value.
If s1 is greater than s2, the function returns a positive integer value.
If s1 is equal to s2, the function returns zero.
 char str1[] = "Hella, world!";
 char str2[] = "Hello, there!";
 a < o = 97-111 = -14
char str1[] = "Hello, world!";
 char str2[] = "Hella, there!";
 o > a = 111-97 = 14
*/
