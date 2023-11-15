/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:40:48 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/30 16:37:40 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_envs *ls_envs)
{
	int		i;
	char	*path;

	i = -1;
	path = get_env_var(ls_envs, "PATH");
	if (!path)
	{
		ft_putendl_fd("minishell: env: No such file or directory",
			STDERR_FILENO);
		return (127);
	}
	free(path);
	while (ls_envs->envs[++i])
		ft_printf("%s\n", ls_envs->envs[i], 1);
	return (0);
}
