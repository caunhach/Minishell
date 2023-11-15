/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:26:28 by wamonvor          #+#    #+#             */
/*   Updated: 2023/10/02 13:12:18 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 		*(unsigned char *)(s + i++) = (char)(c);
// 	return (s);
// }
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (len--)
		*p++ = (unsigned char)c;
	return (s);
}
/*
The function is writes len bytes of value c to the string s.
Returns its first argument.

sets a block of memory to a particular value. The function takes three arguments:
a pointer to the memory block to be set, the value to be set, and the number of 
bytes to be set.
sample 
  memset(arr, 'a', 10);
  char arr[20] = "hello, world!";
result  
Before: hello, world!
After:  aaaaaaaaaa, world!
*/