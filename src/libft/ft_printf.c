/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:08:27 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/23 21:51:55 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	print_char(char arg, int output)
{
	ft_putchar_fd(arg, output);
	return (1);
}

int	print_args(char c, void *args, int output)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_char(*(char *)args, output);
	else if (c == 's')
		i += print_str((char *)args, output);
	else if (c == 'd' || c == 'i')
		i += print_int(*(int *)args, output);
	return (i);
}

int	ft_printf(const char *s, void *parameter, int output)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			if (ft_strchr("csdi", *(s + 1)))
				i += print_args(*(s + 1), parameter, output);
			else if (*(s + 1) == '%')
				i += print_char('%', output);
			s += 2;
		}
		else if (*s == '%' && !*(s + 1))
			break ;
		else
		{
			i += print_char(*s, output);
			s++;
		}
	}
	return (i);
}

int	print_str(char *arg, int output)
{
	int	i;

	if (arg == NULL)
	{
		ft_putstr_fd("(null)", output);
		i = 6;
		return (i);
	}
	i = ft_strlen(arg);
	ft_putstr_fd(arg, output);
	return (i);
}
