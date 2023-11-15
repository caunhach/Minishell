/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:22:51 by wamonvor          #+#    #+#             */
/*   Updated: 2023/11/06 17:31:07 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	restart_shellcmd(t_cmds *ls_cmds, t_envs *env, int *ret, char **a)
{
	int	i;

	i = 0;
	if (ls_cmds->ls_lexers)
		lexer_first(ls_cmds);
	cmds_first(&ls_cmds);
	i = is_singlecomand(ls_cmds);
	if (i == 0)
		*ret = single_execution(ls_cmds);
	else
		*ret = execution(ls_cmds);
	if (a != NULL)
		free_array(a);
	ls_cmds = NULL;
	ls_cmdsinit(&ls_cmds, env);
	init_signals(1);
	loopshellcmds(ls_cmds, env, ret);
	return (0);
}

void	start_executprocess(t_cmds *ls_cmds, t_envs *env, int *ret, char *g)
{
	char	*tmp;
	char	**a;
	int		i;
	int		retx;
	int		ispipe;

	tmp = NULL;
	i = -1;
	a = parse_input(g, 0, 0);
	tokencheck(a, ls_cmds, env);
	while (a[++i] != NULL)
	{
		if (pipe_sign(a[i]) > 0)
			ispipe = 1;
		if (dollar_sign(a[i]) > 0)
		{
			tmp = expand_variable(ls_cmds, a[i], ret, ispipe);
			free(a[i]);
			a[i] = tmp;
		}
		if (a[i][0] != '\0')
			parse_arg(&ls_cmds, a[i], env);
	}
	free(g);
	restart_shellcmd(ls_cmds, env, &retx, a);
}

void	loopshellcmds(t_cmds *ls_cmds, t_envs *env, int *ret)
{
	char	*argg;

	argg = readline(READLINE_MSG);
	add_history(argg);
	if (argg == NULL)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		free(argg);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	if (contains_only_whitespace(argg))
		miniloop(ls_cmds, env, ret, argg);
	if (argg == NULL || ft_strcmp(argg, "") == 0)
		miniloop(ls_cmds, env, ret, argg);
	if (argg[0] == '\0')
		miniloop(ls_cmds, env, ret, argg);
	if (!count_quotes(argg))
	{
		ft_putstr_fd("parse error\n", STDOUT_FILENO);
		miniloop(ls_cmds, env, ret, argg);
	}
	start_executprocess(ls_cmds, env, ret, argg);
}

int	main(int argc, char **argv, char **envp)
{
	t_envs	*ls_envs;
	t_cmds	*ls_cmds;
	int		*ret;

	(void)argc;
	(void)argv;
	(void)envp;
	ls_cmds = NULL;
	ls_envs = NULL;
	ret = NULL;
	parse_env(&ls_envs, envp);
	incrementshlvl(ls_envs);
	init_signals(1);
	update_dir(ls_envs, NULL);
	ls_cmdsinit(&ls_cmds, ls_envs);
	loopshellcmds(ls_cmds, ls_envs, ret);
	free_cmds_list(ls_cmds);
	free_envs(ls_envs);
	return (0);
}

void	free_cmds_list(t_cmds *head)
{
	t_cmds	*current;
	int		i;

	while (head != NULL)
	{
		current = head;
		if (current->cmds)
		{
			i = 0;
			while (current->cmds[i] != NULL)
			{
				free(current->cmds[i]);
				i++;
			}
			free(current->cmds);
		}
		if (current->hd_filename)
			free(current->hd_filename);
		head = current->next;
		free(current);
	}
}
