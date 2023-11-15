/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:21:37 by wamonvor          #+#    #+#             */
/*   Updated: 2023/10/02 12:44:46 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*ptr;

	if (nmeb >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(nmeb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}
/*
calloc and molloc use for allocates memory 

but colloc is allocates memory for an array of count elements, 
each of size , and initializes the memory to zero. 

for molloc does not clear and initializes allocated memory

The function works by first checking for integer overflow 
in the multiplication of count and size. If an overflow 
is detected, the function returns NULL.

If there is no overflow, the function uses the malloc function
to allocate a block of memory of size count * size. 
If malloc fails to allocate the memory, the function returns NULL.

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;   // Pointer to the allocated memory block

	// Check for integer overflow in the multiplication of count and size
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);

	// Allocate a block of memory of size count * size
	ptr = (void *)malloc(count * size);

	// If malloc fails to allocate the memory, return NULL
	if (ptr == NULL)
		return (NULL);

	// Use ft_bzero to initialize the memory to zero
	ft_bzero (ptr, count * size);

	// Return a pointer to the allocated memory block
	return (ptr);
}

int *arr = (int *)ft_calloc(10, sizeof(int));
This would allocate a block of memory for an array of 10 integers,
 and initialize the memory to zero. The resulting pointer 
would be stored in the variable arr.







*/
