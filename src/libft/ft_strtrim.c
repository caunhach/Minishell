/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:48:05 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 13:02:50 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (set == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL)
	{
		start++;
		if (start == ft_strlen(s1))
			return (ft_strdup(""));
	}
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL)
		start++;
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[len]) != NULL)
		len--;
	return (ft_substr(s1, start, (len - start + 1)));
}
/*
The function is copy the string s1 in new string,
remove the set of charactere at begining and end of s1.
Return the new trimmed string.
#include <stdio.h>
#include <stdlib.h>
#include "strtrim.h"

int main() {
    char *input_str = "   hello, world!   ";
    char *trimmed_str = strtrim(input_str, " ,!");

    if (trimmed_str == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    printf("Input string: '%s'\n", input_str);
    printf("Trimmed string: '%s'\n", trimmed_str);

    free(trimmed_str);

    return 0;
}
Input string: '   hello, world!   '
Trimmed string: 'hello'
*/
