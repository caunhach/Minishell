/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:59:38 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/30 17:40:46 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pre_exec_cmd(t_cmds *ls_cmds)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (ls_cmds->ls_lexers)
		if (check_redirect(ls_cmds))
			exit(1);
	if (!ls_cmds->cmds)
		exit(0);
	if (is_builtin(ls_cmds))
		exit_status = exec_builtin(ls_cmds);
	else if (ls_cmds->cmds[0][0] != '\0')
		exit_status = exec_cmd(ls_cmds);
	else
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(ls_cmds->cmds[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit_status = 127;
	}
	exit (exit_status);
}

int	parent_fork(t_cmds *ls_cmds, int *fd_in)
{
	if (ls_cmds->next)
		close(ls_cmds->pipes[1]);
	if (ls_cmds->next)
	{
		if (ls_cmds->hd_filename)
		{
			close(ls_cmds->pipes[0]);
			*fd_in = open(ls_cmds->hd_filename, O_RDONLY);
		}
		else
			*fd_in = ls_cmds->pipes[0];
	}
	return (EXIT_SUCCESS);
}

int	child_fork(t_cmds *ls_cmds, int fd_in)
{
	if (ls_cmds->previous && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error("Failed to dup2\n");
	if (ls_cmds->next && dup2(ls_cmds->pipes[1], STDOUT_FILENO) < 0)
		ft_error("Failed to dup2\n");
	if (ls_cmds->previous)
		close(fd_in);
	pre_exec_cmd(ls_cmds);
	return (EXIT_SUCCESS);
}

int	ft_fork(t_cmds *ls_cmds, int *fd_in)
{
	ls_cmds->pid = fork();
	if (ls_cmds->pid < 0)
		ft_error("Failed to fork\n");
	else if (ls_cmds->pid == 0)
	{
		child_fork(ls_cmds, *fd_in);
	}
	return (EXIT_SUCCESS);
}

int	execution(t_cmds *ls_cmds)
{
	int		fd_in;
	int		exit_status;
	t_cmds	*head;

	head = ls_cmds;
	fd_in = STDIN_FILENO;
	exit_status = EXIT_SUCCESS;
	start_heredoc(ls_cmds);
	ls_cmds = head;
	while (ls_cmds)
	{
		expand_cmd_and_lexers(ls_cmds);
		if (ls_cmds->next)
		{
			if (pipe(ls_cmds->pipes) < 0)
				ft_error("Failed to pipe\n");
		}
		exit_status = ft_fork(ls_cmds, &fd_in);
		parent_fork(ls_cmds, &fd_in);
		ls_cmds = ls_cmds->next;
	}
	exit_status = pipe_wait(head);
	return (exit_status);
}
