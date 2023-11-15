/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:49:41 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/30 16:52:38 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

int	ft_exit(t_cmds *ls_cmds)
{
	int	i;

	i = 0;
	if (env_len(ls_cmds->cmds) == 1)
		exit_fatal_message(ls_cmds, "exit\n", 0);
	else if (env_len(ls_cmds->cmds) >= 2)
	{
		while (ls_cmds->cmds[1][i])
		{
			if (!ft_isdigitplus(ls_cmds->cmds[1][i]))
			{
				ft_printf("exit\nminishell: exit: %s:", ls_cmds->cmds[1], 1);
				exit_fatal_message(ls_cmds, " numeric arguments required\n",
					255);
				return (1);
			}
			i++;
		}
		if (env_len(ls_cmds->cmds) == 2)
			exit_fatal_message(ls_cmds, "exit\n", ft_atoi(ls_cmds->cmds[1]));
		else
			ft_printf("exit\nminishell: exit: too many arguments\n", "", 1);
		return (1);
	}
	return (0);
}

int	hasn(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int	ft_echo(t_cmds *ls_cmds)
{
	int		i;
	int		option;
	char	**cmds;

	i = 1;
	option = 0;
	cmds = ls_cmds->cmds;
	if (count_cmds(cmds) > 1)
	{
		if ((cmds[i][0] == '-') && hasn(cmds[i]) == 1)
		{
			option = 1;
			i++;
		}
		while (cmds[i])
		{
			ft_putstr_fd(cmds[i], 1);
			if (cmds[i][0] != '\0' && cmds[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (!option)
		write(1, "\n", 1);
	return (0);
}

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}
