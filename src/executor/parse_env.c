/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:39:21 by caunhach          #+#    #+#             */
/*   Updated: 2023/09/28 16:52:11 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
	}
	return (ft_strdup("\0"));
}

char	*get_pwd(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PWD=", 4))
			return (ft_substr(envp[i], 4, ft_strlen(envp[i]) - 4));
	}
	return (ft_strdup("\0"));
}

char	*get_old_pwd(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "OLDPWD=", 7))
			return (ft_substr(envp[i], 7, ft_strlen(envp[i]) - 7));
	}
	return (ft_strdup("\0"));
}

int	parse_env(t_envs **ls_envs, char **env)
{
	char	*path_env;
	char	*tmp;
	int		i;

	*ls_envs = (t_envs *)malloc(sizeof(t_envs));
	if (!*ls_envs)
		ft_error("Failed to parse env\n");
	(*ls_envs)->envs = dup_array(env);
	path_env = get_path((*ls_envs)->envs);
	(*ls_envs)->path = ft_split(path_env, ':');
	free(path_env);
	i = -1;
	while ((*ls_envs)->path[++i])
	{
		if (ft_strncmp(&(*ls_envs)->path[i]
				[ft_strlen((*ls_envs)->path[i]) - 1], "/", 1) != 0)
		{
			tmp = ft_strjoin((*ls_envs)->path[i], "/");
			free((*ls_envs)->path[i]);
			(*ls_envs)->path[i] = tmp;
		}
	}
	return (EXIT_SUCCESS);
}

int	update_dir(t_envs *ls_envs, char *new_pwd)
{
	char	**envp;

	envp = ls_envs->envs;
	if (!new_pwd)
	{
		ls_envs->pwd = get_pwd(envp);
		ls_envs->old_pwd = get_old_pwd(envp);
		if (!ls_envs->pwd || !ls_envs->old_pwd)
			ft_error("Failed to set pwd\n");
	}
	else
	{
		free(ls_envs->old_pwd);
		ls_envs->old_pwd = ft_strdup(ls_envs->pwd);
		free(ls_envs->pwd);
		ls_envs->pwd = ft_strdup(new_pwd);
		if (update_env(ls_envs))
			ft_error("Failed to updated pwd in env");
	}
	return (0);
}
