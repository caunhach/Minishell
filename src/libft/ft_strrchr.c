/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:57:48 by wamonvor          #+#    #+#             */
/*   Updated: 2023/02/27 13:29:03 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
The function is locates the last occurence of c
in the string pointed to by s, this included the 
null character.
Return a pointer to the located character.

must be cast const char to char * because 
This is possible because s is declared as a const char *, 
so it points to a constant string and we cast it to char * to 
remove the const qualifier

The expression (s + i) adds the value of i to 
the address pointed 
to by s, which moves the pointer to the memory location 
of the character at index i in the string s. 
Since s is a pointer to a const char and we want to return a
pointer to a char,
we cast the result of (s + i) to a char * using the (char *) 
type cast.

sampel 
int main() {
    char haystack[] = "hello, world!";
    char needle[] = "world";
    char *result = ft_strrchr(haystack, needle, strlen(haystack));
    if (result != NULL) {
        printf("Substring found at position %ld: %s\n"
		, result - haystack, result);
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}

result 
Substring found at position 7: world!


*/
