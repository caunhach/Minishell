/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_readline2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:45:41 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/23 21:11:35 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	is_onstr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == ch)
			return (true);
		i++;
	}
	return (false);
}

char	*remove_quotes(char *parsed, size_t i, size_t j)
{
	char	start_quote;
	char	*unquoted_parsed;

	start_quote = '\0';
	unquoted_parsed = malloc((strlen(parsed) + 1) * sizeof(char));
	if (!unquoted_parsed)
		return (NULL);
	while (parsed[++i])
	{
		if (is_onstr(QUOTES, parsed[i]))
		{
			if (start_quote == '\0')
				start_quote = parsed[i];
			else if (start_quote == parsed[i])
				start_quote = '\0';
			else
				unquoted_parsed[j++] = parsed[i];
		}
		else
			unquoted_parsed[j++] = parsed[i];
	}
	unquoted_parsed[j] = '\0';
	return (unquoted_parsed);
}

int	my_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

bool	contains_only_whitespace(const char *input)
{
	size_t	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!isspace((unsigned char)input[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

int	ls_cmdsinit(t_cmds **ls_cmds, t_envs *env)
{
	t_cmds	*new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new)
		return (exit_fatal());
	new->cmds = NULL;
	new->hd_filename = NULL;
	new->len_cmd = 0;
	new->previous = NULL;
	new->next = NULL;
	new->ls_envs = env;
	new->ls_lexers = NULL;
	new->exitstatus = 0;
	if (*ls_cmds)
	{
		(*ls_cmds)->next = new;
		new->previous = *ls_cmds;
	}
	else
		*ls_cmds = new;
	return (0);
}
