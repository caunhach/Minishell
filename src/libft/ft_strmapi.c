/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:54:57 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/28 13:17:21 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  (*f) can use (f) */
/* strdup use for declare memory , can use malloc also*/
#include "libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (!(str))
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
The function is apply the function f to each characters of the string s.
Return the new string creat in malloc memory,

sameple 
char toupper_helper(unsigned int i, char c)
{
    return toupper(c);
}
int main() {
    char src[] = "hello, world!";
    char *result = ft_strmapi(src, toupper_helper);
    printf("%s\n", result);
    free(result);
    return 0;
}
you will get HELLO, WORLD! in memory
*/
