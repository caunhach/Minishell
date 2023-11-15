/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:33:42 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/27 21:20:54 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_cmd2(t_cmds *c, char *path, t_envs	*ptr_envs)
{
	if (execve(path, c->cmds, ptr_envs->envs) == -1)
	{
		if (access(c->cmds[0], F_OK) == 0 && access(c->cmds[0], X_OK) == -1)
		{
			ft_printf("minishell: %s: Permission denied\n", c->cmds[0], 2);
			return (126);
		}
		if (ft_strchr(c->cmds[0], '/') != NULL)
		{
			ft_printf("minishell: %s: is a directory\n", c->cmds[0], 2);
			return (126);
		}
		ft_printf("minishell: %s: : command not found\n", c->cmds[0], 2);
		return (127);
	}
	return (EXIT_SUCCESS);
}
