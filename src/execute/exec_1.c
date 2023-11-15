/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:01:15 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/30 16:13:36 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_singlecomand(t_cmds *ls_cmds)
{
	int	j;
	int	i;

	j = 0;
	while (ls_cmds->cmds)
	{
		if (ls_cmds->cmds != NULL)
		{
			i = 0;
			while (ls_cmds->cmds[i] != NULL)
				i++;
		}
		if (ls_cmds->next)
		{
			ls_cmds = ls_cmds->next;
			j++;
		}
		else
			break ;
	}
	return (j);
}

// int	print2chararray(char **input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i] != NULL)
// 	{
// 		ft_printf("std[%i] :", (void *)&i, 1);
// 		ft_printf(" %s\n", input[i], 1);
// 		i++;
// 	}
// 	return (0);
// }

// int	printdata(t_cmds *ls_cmds)
// {
// 	while (ls_cmds->cmds)
// 	{
// 		if (ls_cmds->cmds != NULL) {
//         int i = 0;
//         while (ls_cmds->cmds[i] != NULL) {
//
//             printf("str[%d]: %s\n", i, ls_cmds->cmds[i]);
//             i++;
//         }
// 		}
// 		if (ls_cmds->next)
// 			ls_cmds = ls_cmds->next;
// 		else 
// 			break;
// 	}
// 	return (EXIT_SUCCESS);
// }
//
// int printchararray(char *input)
// {
// 	    for (int i = 0; input[i] != '\0'; i++) {
//         putchar(input[i]);
//     }
//     putchar('\n');
// 	return(1);
// }
