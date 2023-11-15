/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:12:44 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 14:00:11 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*mem_free(char **tab, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(*tab);
	return (NULL);
}

static int	count_str(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (count);
	if (s[i] != c && i == 0)
	{
		count++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c && i > 0)
			count++;
		i++;
	}
	return (count);
}

static char	*tab_line(char const *s, int i, char c)
{
	char	*str;
	int		index;
	size_t	len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (k <= i)
	{
		len = 0;
		while (s[j] == c)
			j++;
		index = j;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			len++;
		}
		if (k == i)
			str = ft_substr(s, index, len);
		k++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		line;
	int		i;

	if (s == NULL)
		return (NULL);
	line = count_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (line + 1));
	if (tab == NULL)
		return (0);
	tab[line] = NULL;
	i = 0;
	while (i < line)
	{
		tab[i] = tab_line(s, i, c);
		if (tab[i] == NULL)
			return (mem_free(tab, i));
		i++;
	}
	return (tab);
}
/*
The function is use character c delimiter to split a string s.
Free the memory allocated by malloc after all the split is done.
will Return the array of new strings.

It uses the tab_line function to create a substring for 
each index i by finding the start index of the substring and its length.

Note that this implementation does not handle consecutive delimiters or 
leading/trailing delimiters. Also, this function is not protected against
stack overflow or infinite loop when passed a very long string.
fix by 
static char	*tab_line(char const *s, int i, char c)
{
	char	*str;
	int		index;
	size_t	len;
	int		j;

	j = 0;
	while (s[j] == c)
		j++;
	index = j;
	while (j <= i && s[j] != '\0')
	{
		if (s[j] == c && (j == 0 || s[j - 1] != c))
			break;
		j++;
	}
	len = j - index;
	str = ft_substr(s, index, len);
	return (str);
}

count a string as a word if it starts with a non-delimiter character 
and either ends with a delimiter or is the last non-empty 
substring in the string. In tab_line, we now stop processing 
the string when we encounter two consecutive delimiters or reach 
the end of the string.
*/
