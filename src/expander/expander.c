/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:31:19 by caunhach          #+#    #+#             */
/*   Updated: 2023/11/06 14:46:07 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_digit_after_dollar(int j, char *str)
{
	int	i;

	i = j;
	if (str[i] == '$')
	{
		if (ft_isdigit(str[i + 1]))
			i += 2;
	}
	return (i - j);
}

char	*new_function(char *tmp, char c)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = char_to_str(c);
	tmp3 = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (tmp3);
}

char	*expand_variable(t_cmds *ls_cmds, char *str, int *ret, int ispipe)
{
	t_print	*myprint;
	char	*tmp;
	int		i;

	myprint = malloc(sizeof(t_print));
	init_expan(myprint);
	tmp = ft_strdup("\0");
	i = 0;
	while (str[i])
	{
		is_print(myprint, str[i]);
		i += handle_digit_after_dollar(i, str);
		if (str[i] == '$' && (str[i + 1] != '?' && str[i + 1] != ' '
				&& (str[i + 1] != '"' || str[i + 2])) && str[i + 1]
			&& myprint->print == 0)
			i += loop_for_dollar_sign(ls_cmds, str, &tmp, i);
		else if (str[i] == '$' && (str[i + 1] == '?') && myprint->print == 0)
			i += loop_for_dollar_exitstatus(&tmp, ret, ispipe);
		else
			tmp = new_function(tmp, str[i++]);
	}
	if (ls_cmds != NULL)
		ls_cmds = ls_cmds->next;
	free(myprint);
	return (tmp);
}

int	process_env_variable(char **tmp, char *envs)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = ft_strdup(envs + equal_sign(envs));
	tmp3 = ft_strjoin(*tmp, tmp2);
	free(*tmp);
	free(tmp2);
	*tmp = tmp3;
	return (equal_sign(envs));
}

int	loop_for_dollar_sign(t_cmds *ls_cmds, char *str, char **tmp, int i)
{
	int		j;
	char	**envs;
	int		ret;

	j = 0;
	ret = 0;
	envs = ls_cmds->ls_envs->envs;
	while (envs[j])
	{
		if (!ft_strncmp(str + i + 1, envs[j], equal_sign(envs[j]) - 1)
			&& len_no_specific(str, i) - i == (int)equal_sign(envs[j]))
		{
			ret = process_env_variable(tmp, envs[j]);
		}
		j++;
	}
	if (!ret)
		ret = len_no_specific(str, i) - i;
	return (ret);
}

// char	*append_char(char *str, char c)
// {
// 	char	*tmp;
// 	char	*result;

// 	tmp = char_to_str(c);
// 	result = ft_strjoin(str, tmp);
// 	free(tmp);
// 	return (result);
// }

// char	*expand_variable(t_cmds *ls_cmds, char *str, int *ret)
// {
// 	t_print	*myprint;
// 	char	*tmp;
// 	char	*result;
// 	int		i;

// 	myprint = malloc(sizeof(t_print));
// 	i = init_expan(myprint);
// 	tmp = ft_strdup("\0");
// 	while (str[i])
// 	{
// 		is_print(myprint, str[i]);
// 		i += handle_digit_after_dollar(i, str);
// 		if (str[i] == '$' && (str[i + 1] != '?' && str[i + 1] != ' '
// 				&& (str[i + 1] != '"' || str[i + 2])) && str[i + 1]
// 			&& myprint->print == 0)
// 			i += loop_for_dollar_sign(ls_cmds, str, &tmp, i);
// 		else if (str[i] == '$' && (str[i + 1] == '?') && myprint->print == 0)
// 			i += loop_for_dollar_exitstatus(&tmp, ret);
// 		else
// 			result = append_char(result, str[i++]);
// 	}
// 	if (ls_cmds != NULL)
// 		ls_cmds = ls_cmds->next;
// 	free(myprint);
// 	return (tmp);
// }
// void	process_env_variable(char **tmp, char *env_var)
// {
// 	char	*tmp2;
// 	char	*tmp3;

// 	tmp2 = ft_strdup(env_var);
// 	tmp3 = ft_strjoin(*tmp, tmp2);
// 	free(*tmp);
// 	*tmp = tmp3;
// 	free(tmp2);
// }

// int	loop_for_dollar_sign(t_cmds *ls_cmds, char *str, char **tmp, int i)
// {
// 	char	**envs;
// 	int		j;
// 	int		ret;

// 	envs = ls_cmds->ls_envs->envs;
// 	j = 0;
// 	ret = 0;
// 	while (envs[j])
// 	{
// 		if (!ft_strncmp(str + i + 1, envs[j], equal_sign(envs[j]) - 1)
// 			&& len_no_specific(str, i) - i == (int)equal_sign(envs[j]))
// 		{
// 			process_env_variable(tmp, envs[j]);
// 			ret = strlen(envs[j]) - 1;
// 		}
// 		j++;
// 	}
// 	if (!ret)
// 		ret = len_no_specific(str, i) - i;
// 	return (ret);
// }
