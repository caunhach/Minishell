/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:43:24 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/26 09:19:06 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	hasslash(char *str)
{
	while (*str)
	{
		if (*str != '/')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	is_path_here(char **envs)
{
	int	i;

	i = -1;
	while (envs[++i])
	{
		if (!ft_strncmp(envs[i], "PATH=", 5))
			return (0);
	}
	return (1);
}

char	*get_path_cmd(char *cmd, char **ls_path)
{
	int		i;
	char	*tmp_path;

	i = -1;
	while (ls_path[++i])
	{
		tmp_path = ft_strjoin(ls_path[i], cmd);
		if (access(tmp_path, F_OK) == 0)
			return (tmp_path);
		free(tmp_path);
	}
	return (cmd);
}

int	exec_cmd(t_cmds *c)
{
	char	*path;
	t_envs	*ptr_envs;

	ptr_envs = c->ls_envs;
	if (is_path_here(c->ls_envs->envs) || ft_strchr(c->cmds[0], '/') != NULL)
	{
		if (!hasslash(c->cmds[0]) && access(c->cmds[0], F_OK) != 0)
			return (dir_error(c->cmds[0]));
		else if (hasslash(c->cmds[0]) && access(c->cmds[0], F_OK) != 0)
		{
			if (access(c->cmds[0], F_OK) == 0 && access(c->cmds[0], X_OK) == -1)
				ft_printf("minishell: %s: Permission denied\n", c->cmds[0], 2);
			else
				ft_printf("minishell: %s: is a directory\n", c->cmds[0], 2);
			return (126);
		}
	}
	path = get_path_cmd(c->cmds[0], ptr_envs->path);
	return (exec_cmd2(c, path, ptr_envs));
}

int	pipe_wait(t_cmds *ls_cmds)
{
	int	status;
	int	exit_status;

	while (ls_cmds->next != NULL)
	{
		waitpid(ls_cmds->pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		ls_cmds = ls_cmds->next;
	}
	waitpid(ls_cmds->pid, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}
