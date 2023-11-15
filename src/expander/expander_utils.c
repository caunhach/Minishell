/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:11:21 by caunhach          #+#    #+#             */
/*   Updated: 2023/11/06 14:22:26 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int	len_no_specific(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '$' && str[i] != ' '
		&& str[i] != '!' && str[i] != '#' && str[i] != '@'
		&& str[i] != '%' && str[i] != '&' && str[i] != '*'
		&& str[i] != ')' && str[i] != '(' && str[i] != '+'
		&& str[i] != '\"' && str[i] != '\'' && str[i] != '='
		&& str[i] != '\\' && str[i] != '?' && str[i] != '^'
		&& str[i] != '-' && str[i] != ':' && str[i] != '/')
		i++;
	return (i);
}

size_t	pipe_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*delete_quotes(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			ft_strlcpy(&str[i], &str[i + j], ft_strlen(str) - i);
		}
		i++;
	}
	return (str);
}
