/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:33:42 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/18 00:09:10 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cmds_first(t_cmds **ls_cmds)
{
	while (*ls_cmds && (*ls_cmds)->previous)
		*ls_cmds = (*ls_cmds)->previous;
	return (EXIT_SUCCESS);
}

int	cmds_add(t_cmds *ls_cmds, char *args)
{
	char	**tmp;
	int		i;
	char	*s1;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (ls_cmds->len_cmd + 2));
	if (!tmp)
		return (exit_fatal());
	while (++i < ls_cmds->len_cmd)
		tmp[i] = ls_cmds->cmds[i];
	if (ls_cmds->len_cmd)
		free(ls_cmds->cmds);
	s1 = remove_quotes(args, -1, 0);
	ls_cmds->cmds = tmp;
	ls_cmds->type = 1;
	ls_cmds->cmds[i++] = ft_strdup(s1);
	ls_cmds->cmds[i] = 0;
	ls_cmds->len_cmd++;
	free(s1);
	return (EXIT_SUCCESS);
}

int	is_pipe(t_lexers *ls_lexers)
{
	while (ls_lexers)
	{
		if (ls_lexers->types == PIPE)
			return (1);
		ls_lexers = ls_lexers->next;
	}
	return (0);
}

int	parse_arg(t_cmds **ls_cmds, char *args, t_envs *env)
{
	if (!*ls_cmds || is_pipe((*ls_cmds)->ls_lexers))
		return (cmds_push(ls_cmds, args, env));
	else if (ft_strncmp("|", args, 1) == 0)
	{
		lexers_push(*ls_cmds, args);
		lexer_first(*ls_cmds);
		return (0);
	}
	else if (is_redirect(args))
		return (lexers_push(*ls_cmds, args));
	else if ((*ls_cmds)->ls_lexers && !(*ls_cmds)->ls_lexers->str)
		return (lexers_add((*ls_cmds)->ls_lexers, args));
	else
		return (cmds_add(*ls_cmds, args));
	return (EXIT_SUCCESS);
}

int	lexer_first(t_cmds *ls_cmds)
{
	while (ls_cmds->ls_lexers->previous)
		ls_cmds->ls_lexers = ls_cmds->ls_lexers->previous;
	return (EXIT_SUCCESS);
}
