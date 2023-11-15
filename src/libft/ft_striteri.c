/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:37:13 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:47:16 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
		s[i] = '\0';
	}
}

/*
The function have pass the function pointed by f argument 
to every characteres of the string s.
#include <stdio.h>

void print_index_char(unsigned int i, char* c) {
    printf("Character at index %d: %c\n", i, *c);
}

int main() {
    char str[] = "Hello, World!";
    ft_striteri(str, print_index_char);
    return 0;
}
Character at index 0: H
Character at index 1: e
Character at index 2: l
Character at index 3: l
Character at index 4: o
Character at index 5: ,
Character at index 6:  
Character at index 7: W
Character at index 8: o
Character at index 9: r
Character at index 10: l
Character at index 11: d
Character at index 12: !
*/
