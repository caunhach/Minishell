/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_checktoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:20:56 by wichitt           #+#    #+#             */
/*   Updated: 2023/11/06 14:22:30 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	countarraysize(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_operator(char *str)
{
	return (ft_strcmp(str, "|") == 0
		|| ft_strcmp(str, "<") == 0
		|| ft_strcmp(str, "<<") == 0
		|| ft_strcmp(str, ">>") == 0
		|| ft_strcmp(str, ">") == 0);
}

bool	is_valid_sequence(char **std, int i, int max)
{
	if (i + 1 > max)
	{
		if (is_operator(std[i]))
			return (false);
		return (true);
	}
	if (i == 0)
	{
		if (is_operator(std[i]))
		{
			if (ft_strcmp(std[i], "|") == 0)
				return (false);
			if (is_operator(std[i + 1]))
				return (false);
		}
		return (true);
	}
	if (is_operator(std[i]))
	{
		if (is_operator(std[i - 1]))
			return (false);
		if (is_operator(std[i + 1]))
			return (false);
	}
	return (true);
}

int	functioncheck(char **a)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (a[i])
	{
		if (!is_valid_sequence(a, i, countarraysize(a) - 1))
		{
			if (ft_strcmp(a[i], "|") == 0)
				return (1);
			else
				type = 2;
		}
		i++;
	}
	return (type);
}

void	checkcmd_lexer(int type)
{
	if (type == 1)
		ft_printf("syntax error near unexpected token `|'\n", "", 2);
	else
		ft_printf("syntax error near unexpected token `newline'\n", "", 2);
}
