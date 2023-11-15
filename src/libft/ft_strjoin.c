/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:48:33 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 12:27:26 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_new_s;

	if (s1 == NULL)
		return (NULL);
	len_new_s = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = (char *)malloc(len_new_s * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	ft_strlcpy(new_s, s1, len_new_s);
	ft_strlcat(new_s, (char *)s2, len_new_s);
	return (new_s);
}

/*
The function is allocate memory
and concatenate the string s1 and s2 in new string.
Return the new string result.

and we can use memcpy for do like this
char* strjoin(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, str1, len1);
    memcpy(result + len1, str2, len2 + 1);
    return result;
}
*/
