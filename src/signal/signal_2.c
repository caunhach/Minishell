/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:34:38 by wamonvor          #+#    #+#             */
/*   Updated: 2023/11/06 17:31:28 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <termios.h>

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_handler3(int sig)
{
	char	*shlvl_str;

	(void)sig;
	shlvl_str = getenv("SHLVL");
	if (atoi(shlvl_str) == 1)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		kill(0, SIGINT);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
