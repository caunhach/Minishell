/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:36:21 by caunhach          #+#    #+#             */
/*   Updated: 2023/11/06 17:13:16 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**loop_del_var(char **envs, char **rtn, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envs[i])
	{
		if ((ft_strncmp(envs[i], var, equal_sign(envs[i]) - 1)))
		{
			rtn[j] = ft_strdup(envs[i]);
			if (!rtn[j])
			{
				free_array(rtn);
				return (rtn);
			}
			j++;
		}
		i++;
	}
	return (rtn);
}

char	**del_var(char **envs, char *var)
{
	char	**rtn;
	int		i;

	i = 0;
	while (envs[i])
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	rtn = loop_del_var(envs, rtn, var);
	return (rtn);
}

int	check_unset_cmds(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (check_valid_identifier(cmd[i]) || ft_isdigit(cmd[0]))
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(cmd, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_unset(char **cmds)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = EXIT_SUCCESS;
	while (cmds[++i])
	{
		if (check_unset_cmds(cmds[i]))
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}

int	ft_unset(t_cmds *ls_cmds)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (check_unset(ls_cmds->cmds))
		return (EXIT_FAILURE);
	else
	{
		while (ls_cmds->cmds[++i])
		{
			tmp = del_var(ls_cmds->ls_envs->envs,
					ls_cmds->cmds[i]);
			free_array(ls_cmds->ls_envs->envs);
			ls_cmds->ls_envs->envs = tmp;
		}
	}
	return (EXIT_SUCCESS);
}
