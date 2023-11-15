/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:58:47 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/28 17:03:56 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_array(char **arr, char *str)
{
	int	i;

	i = -1;
	ft_printf("%s :\n", str, 1);
	while (arr[++i])
		ft_printf("%s\n", arr[i], 1);
}

void	print_pwd(t_envs *ls_envs)
{
	ft_printf("PWD : %s\n", ls_envs->pwd, 1);
	ft_printf("OLDPWD : %s\n", ls_envs->old_pwd, 1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**dup_array(char **env)
{
	size_t	i;
	size_t	len;
	char	**res;

	i = -1;
	len = 0;
	while (env[++i])
		len++;
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		res[i] = ft_strdup(env[i]);
		if (!res[i])
		{
			free_array(res);
			return (res);
		}
	}
	res[i] = 0;
	return (res);
}

int	start_heredoc(t_cmds *ls_cmds)
{
	while (ls_cmds)
	{
		heredoc_main(ls_cmds);
		ls_cmds = ls_cmds->next;
	}
	return (EXIT_SUCCESS);
}
// void	print_cmds(t_cmds *ls_cmds)
// {
// 	int		i;
// 	int		j;

// 	i = 1;
// 	j = -1;
// 	while (ls_cmds)
// 	{
// 		printf("cmds [%i] :", i++);
// 		j = -1;
// 		while (ls_cmds->cmds[++j])
// 			printf(" [%s] ", ls_cmds->cmds[j]);
// 		printf("\n");
// 		if (ls_cmds->ls_lexers)
// 		{
// 			while (ls_cmds->ls_lexers->next)
// 			{
// 				printf("str : [%s]\n", ls_cmds->ls_lexers->str);
// 				printf("types : [%i]\n", ls_cmds->ls_lexers->types);
// 				ls_cmds->ls_lexers = ls_cmds->ls_lexers->next;
// 			}
// 			printf("str : [%s]\n", ls_cmds->ls_lexers->str);
// 			printf("types : [%i]\n", ls_cmds->ls_lexers->types);
// 			lexer_first(ls_cmds);
// 		}
// 		ls_cmds = ls_cmds->next;
// 	}
// }
