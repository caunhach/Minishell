/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:26:24 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/30 17:07:12 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin2(t_cmds *ls_cmds)
{
	char	*cmd;

	if (ls_cmds->cmds)
		cmd = ls_cmds->cmds[0];
	else
		return (0);
	if (!ft_strncmp(cmd, "exit", 4) && (ft_strlen(cmd) == 4))
		return (1);
	else if (!ft_strncmp(cmd, "cd", 2) && (ft_strlen(cmd) == 2))
		return (1);
	else if (!ft_strncmp(cmd, "export", 6) && (ft_strlen(cmd) == 6))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 5) && (ft_strlen(cmd) == 5))
		return (1);
	return (0);
}

int	is_builtin(t_cmds *ls_cmds)
{
	char	*cmd;

	if (ls_cmds->cmds)
		cmd = ls_cmds->cmds[0];
	else
		return (0);
	if (!ft_strncmp(cmd, "exit", 4) && (ft_strlen(cmd) == 4))
		return (1);
	else if (!ft_strncmp(cmd, "echo", 4) && (ft_strlen(cmd) == 4))
		return (1);
	else if (!ft_strncmp(cmd, "pwd", 3) && (ft_strlen(cmd) == 3))
		return (1);
	else if (!ft_strncmp(cmd, "cd", 2) && (ft_strlen(cmd) == 2))
		return (1);
	else if (!ft_strncmp(cmd, "env", 3) && (ft_strlen(cmd) == 3))
		return (1);
	else if (!ft_strncmp(cmd, "export", 6) && (ft_strlen(cmd) == 6))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 5) && (ft_strlen(cmd) == 5))
		return (1);
	return (0);
}

int	exec_builtin(t_cmds *ls_cmds)
{
	int	exit_status;

	exit_status = 0;
	if (!ft_strncmp(ls_cmds->cmds[0], "exit", 4))
		exit_status = ft_exit(ls_cmds);
	else if (!ft_strncmp(ls_cmds->cmds[0], "echo", 4))
		exit_status = ft_echo(ls_cmds);
	else if (!ft_strncmp(ls_cmds->cmds[0], "pwd", 3))
		exit_status = ft_pwd(ls_cmds->ls_envs);
	else if (!ft_strncmp(ls_cmds->cmds[0], "cd", 2))
		exit_status = ft_cd(ls_cmds->cmds, ls_cmds->ls_envs);
	else if (!ft_strncmp(ls_cmds->cmds[0], "env", 3))
		exit_status = ft_env(ls_cmds->ls_envs);
	else if (!ft_strncmp(ls_cmds->cmds[0], "export", 6))
		exit_status = ft_export(ls_cmds, ls_cmds->ls_envs, 1, 0);
	else if (!ft_strncmp(ls_cmds->cmds[0], "unset", 5))
		exit_status = ft_unset(ls_cmds);
	return (exit_status);
}
