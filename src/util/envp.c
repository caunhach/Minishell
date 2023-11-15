/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:42:47 by wamonvor          #+#    #+#             */
/*   Updated: 2023/11/06 14:22:27 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

char	**ft_dupenvp(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
			return (rtn);
		i++;
	}
	return (rtn);
}

void	miniloop(t_cmds *ls_cmds, t_envs *env, int *ret, char *argg)
{
	free(argg);
	loopshellcmds(ls_cmds, env, ret);
}

int	loop_for_dollar_exitstatus(char **tmp, int *ret, int ispipe)
{
	char	*tmp2;
	char	*tmp3;

	if (ret != NULL)
		tmp2 = ft_itoa(*ret);
	else
		tmp2 = ft_strdup("0");
	if (ispipe == 1)
		tmp2 = ft_strdup("0");
	tmp3 = ft_strjoin(*tmp, tmp2);
	free(*tmp);
	*tmp = tmp3;
	free(tmp2);
	return (2);
}

int	incrementshlvl(t_envs *envs)
{
	char	*new_shlvl_var;
	char	*newcharshlvl;
	int		i;
	int		shlvl;

	i = 0;
	shlvl = 1;
	new_shlvl_var = NULL;
	shlvl = ft_atoi(getenv("SHLVL")) + 1;
	newcharshlvl = ft_itoa(shlvl);
	while (envs->envs[i] != NULL)
	{
		if (ft_strncmp(envs->envs[i], "SHLVL", ft_strlen("SHLVL")) == 0)
		{
			new_shlvl_var = ft_strjoin("SHLVL=", newcharshlvl);
			free(envs->envs[i]);
			envs->envs[i] = ft_strdup(new_shlvl_var);
			free(new_shlvl_var);
			free(newcharshlvl);
			return (shlvl);
		}
		i++;
	}
	free(newcharshlvl);
	return (shlvl);
}
