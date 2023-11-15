/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_checktoken2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:20:56 by wichitt           #+#    #+#             */
/*   Updated: 2023/11/06 14:22:29 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokencheck(char **a, t_cmds *ls_cmds, t_envs *env)
{
	int	retx;

	if (functioncheck(a) > 0)
	{
		checkcmd_lexer(functioncheck(a));
		retx = 258;
		if (a != NULL)
			free_array(a);
		ls_cmds = NULL;
		ls_cmdsinit(&ls_cmds, env);
		loopshellcmds(ls_cmds, env, &retx);
	}
}
