/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:23:11 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/27 21:37:17 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	variable_exist(t_cmds *ls_cmds, char *str)
{
	int		i;
	char	**envp;

	i = 0;
	envp = ls_cmds->ls_envs->envs;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (envp[i])
	{
		if (ft_strncmp(envp[i],
				str, equal_sign(envp[i])) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (export_error(str));
	while (str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**loop_add_env(char **arr, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(arr[i]);
		}
		else
			rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_array(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 2);
	if (!rtn)
		return (NULL);
	i = 0;
	loop_add_env(arr, rtn, str);
	return (rtn);
}

int	ft_export(t_cmds *ls_cmds, t_envs *ls_envs, int i, int exit_status)
{
	int		tmp_s;
	char	**tmp;

	if (!ls_cmds->cmds[1])
		print_sorted_env(ls_cmds->ls_envs);
	else
	{
		while (ls_cmds->cmds[i])
		{
			tmp_s = check_parameter(ls_cmds->cmds[i]);
			if (!exit_status && tmp_s == 1)
				exit_status = tmp_s;
			if (tmp_s == 0 && variable_exist(ls_cmds, ls_cmds->cmds[i]) == 0)
			{
				if (ls_cmds->cmds[i])
				{
					tmp = add_var(ls_envs->envs, ls_cmds->cmds[i]);
					free_array(ls_envs->envs);
					ls_envs->envs = tmp;
				}
			}
			i++;
		}
	}
	return (exit_status);
}
