/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:29:23 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/23 21:27:31 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	rl_clear_history();
	exit(EXIT_FAILURE);
}

int	lexers_add(t_lexers *ls_lexers, char *args)
{
	ls_lexers->str = ft_strdup(args);
	if (!ls_lexers->str)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_redirect(char *args)
{
	if (!ft_strncmp(args, "<", ft_strlen(args)))
		return (1);
	else if (!ft_strncmp(args, ">", ft_strlen(args)))
		return (1);
	else if (!ft_strncmp(args, "<<", ft_strlen(args)))
		return (1);
	else if (!ft_strncmp(args, ">>", ft_strlen(args)))
		return (1);
	return (0);
}

int	lexers_push(t_cmds *ls_cmds, char *args)
{
	t_lexers	*new;

	new = (t_lexers *)malloc(sizeof(t_lexers));
	if (!new)
		return (EXIT_FAILURE);
	new->str = NULL;
	if (!ft_strncmp(args, "<", ft_strlen(args)))
		new->types = LESS;
	else if (!ft_strncmp(args, ">", ft_strlen(args)))
		new->types = GREAT;
	else if (!ft_strncmp(args, "<<", ft_strlen(args)))
		new->types = LESS_LESS;
	else if (!ft_strncmp(args, ">>", ft_strlen(args)))
		new->types = GREAT_GREAT;
	else if (!ft_strncmp(args, "|", ft_strlen(args)))
		new->types = PIPE;
	new->previous = NULL;
	new->next = NULL;
	if (ls_cmds->ls_lexers)
	{
		ls_cmds->ls_lexers->next = new;
		new->previous = ls_cmds->ls_lexers;
	}
	ls_cmds->ls_lexers = new;
	return (EXIT_SUCCESS);
}

int	cmds_push(t_cmds **ls_cmds, char *args, t_envs *env)
{
	t_cmds	*new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new)
		return (exit_fatal());
	new->cmds = NULL;
	new->hd_filename = NULL;
	new->len_cmd = 0;
	new->previous = NULL;
	new->next = NULL;
	new->ls_envs = env;
	new->ls_lexers = NULL;
	if (*ls_cmds)
	{
		(*ls_cmds)->next = new;
		new->previous = *ls_cmds;
	}
	*ls_cmds = new;
	if (is_redirect(args))
		return (lexers_push(*ls_cmds, args));
	return (cmds_add(new, args));
}
