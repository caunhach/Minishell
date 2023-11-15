/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:03:11 by caunhach          #+#    #+#             */
/*   Updated: 2023/11/06 17:12:08 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	single_execution(t_cmds *ls_cmds)
{
	int	pid;
	int	status;
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (!ls_cmds->cmds && !ls_cmds->ls_lexers)
		return (0);
	expand_cmd_and_lexers(ls_cmds);
	if (is_builtin2(ls_cmds))
	{
		exit_status = exec_builtin(ls_cmds);
		return (exit_status);
	}
	heredoc_main(ls_cmds);
	pid = fork();
	if (pid < 0)
		ft_error("Failed to fork\n");
	else if (pid == 0)
		pre_exec_cmd(ls_cmds);
	init_signals2();
	waitpid(pid, &status, 0);
	init_signals(1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (exit_status);
}
