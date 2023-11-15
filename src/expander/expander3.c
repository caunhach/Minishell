/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:35:15 by wamonvor          #+#    #+#             */
/*   Updated: 2023/10/16 14:55:31 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**expander_arr(t_cmds *ls_cmds, char **arr)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	(void)ls_cmds;
	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(arr[0], "export", ft_strlen(arr[0]) - 1))
		{
			arr[i] = delete_quotes(arr[i], '\"');
			arr[i] = delete_quotes(arr[i], '\'');
		}
		i++;
	}
	return (arr);
}

char	*expander_str(t_cmds *ls_cmds, char *str)
{
	char	*tmp;

	tmp = NULL;
	(void)tmp;
	(void)ls_cmds;
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\'');
	return (str);
}
