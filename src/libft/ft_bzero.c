/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:21:27 by wamonvor          #+#    #+#             */
/*   Updated: 2023/10/02 13:12:47 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
/*
void *s is a declaration of a pointer variable named s,
which has a data type of void*.

The void data type is a special type in C that represents
the absence of type. It is often used in function declarations 
to indicate that a function does not return a value 
or does not take any arguments.

In the case of void *s, the void* data type indicates that the pointer
variable s can point to an object of any type, but the type of the object
pointed to by s must be specified when the pointer is dereferenced or used
in an operation. This allows the pointer to be used to point to any type 
of data, providing a level of flexibility in programming.

size_t is datatype of unsigned integral variable x.
It is calculating the size of variable a in bytes.
On a 32-bit system size_t will take 32 bits, on a 64-bit one 64 bits.

The function takes two arguments: a pointer to the memory 
to be zeroed (s), and the number of bytes to be zeroed (n).

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;   // Pointer to the memory to be zeroed

	p = (unsigned char *)s;   // Cast the pointer to an unsigned char pointer

	// Iterate over the first n bytes of memory, setting each byte to zero
	while (n--)
		*p++ = 0;
}

char buffer[10];
ft_bzero(buffer, sizeof(buffer));

his would set the first 10 bytes of buffer to zero.

*/