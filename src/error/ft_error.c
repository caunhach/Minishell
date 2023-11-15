/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:28:15 by wamonvor          #+#    #+#             */
/*   Updated: 2023/09/28 19:22:22 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	Check_Unex_Token(t_cmds *ls_cmds)
// {
// 	t_lexers	*head;
// 	int			exit

// 	while(ls_cmds)
// 	{
// 		if (ls_cmds->next == NULL)
// 		{
// 			head = ls_cmds->ls_lexers;
// 			while (ls_cmds->ls_lexers && ls_cmds->ls_lexers->types != PIPES)
// 			{
// 				if (!ls_cmds->ls_lexers->str)
// 				{
// 					ft_putstr_fd("minishell: 
// syntax error near unexpected token 'newline'\n"
// 					, STDERR_FILENO);
// 					return (EXIT_FAILURE);
// 				}
// 			}
// 		}
// 		if (!ls_cmds->cmds && !ls_cmds->ls_lexers->str)
// 		{
// 			ft_putstr_fd("minishell: 
// syntax error near unexpected token ", STDERR_FILENO);
// 			ft_putstr_fd("'|'\n", STDERR_FILENO);
// 			return (EXIT_FAILURE);
// 		}
// 		ls_cmds = ls_cmds->next;
// 	}
// 	return (EXIT_SUCCESS);
// }
// void	ft_error(char *error_msg)
// {
// 	write(STDERR_FILENO, "Error: ", 7);
// 	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
// 	write(STDERR_FILENO, "\n", 1);
// 	exit(EXIT_FAILURE);
// }

// int	ft_error(int error)
// {
// 	(void)error ;
// 	ft_putstr_fd("minishell: ", STDOUT_FILENO);
// 	ft_putstr_fd("Print Error Message\n", STDOUT_FILENO);
// 	return (EXIT_FAILURE);
// }
int	dir_error(char *error_message)
{
	ft_printf("minishell: %s: No such file or directory\n", error_message, 2);
	return (127);
}
