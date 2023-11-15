/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:19:27 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/11 00:09:05 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	expand_cmd_and_lexers(t_cmds *ls_cmds)
{
	t_lexers	*start;

	start = ls_cmds->ls_lexers;
	if (ls_cmds->cmds)
		ls_cmds->cmds = expander_arr(ls_cmds, ls_cmds->cmds);
	while (ls_cmds->ls_lexers)
	{
		if (ls_cmds->ls_lexers->types != LESS_LESS && ls_cmds->ls_lexers->str)
			ls_cmds->ls_lexers->str
				= expander_str(ls_cmds, ls_cmds->ls_lexers->str);
		ls_cmds->ls_lexers = ls_cmds->ls_lexers->next;
	}
	ls_cmds->ls_lexers = start;
	return (EXIT_SUCCESS);
}
