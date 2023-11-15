/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:31:19 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/16 14:48:40 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	is_print(t_print *t_print, char str)
{
	if (str == '"')
	{
		if (t_print->print == 0 && t_print->qu == 0)
			t_print->qu = 1;
		else if (t_print->print == 0 && t_print->qu == 1)
			t_print->qu = 0;
	}
	if (str == '\'')
	{
		if (t_print->qu == 0 && t_print->print == 0)
		{
			t_print->print = 1;
			t_print->sinqu = 1;
		}
		else if (t_print->qu == 1 && t_print->print == 0)
			t_print->print = 0;
		else if (t_print->print == 1 && t_print->sinqu == 1)
		{
			t_print->sinqu = 0;
			t_print->print = 0;
		}
	}
}

int	init_expan(t_print *myprint)
{
	myprint->qu = 0;
	myprint->sinqu = 0;
	myprint->print = 0;
	return (0);
}
