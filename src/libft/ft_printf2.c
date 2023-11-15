/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:08:27 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/23 21:52:49 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	print_int(int arg, int output)
{
	int	i;

	i = 0;
	if (arg == -2147483648)
	{
		i += print_char('-', output);
		i += print_char('2', output);
		i += print_int(147483648, output);
	}
	else if (arg < 0)
	{
		i += print_char('-', output);
		arg *= -1;
		i += print_int(arg, output);
	}
	else if (arg > 9)
	{
		i += print_int(arg / 10, output);
		i += print_int(arg % 10, output);
	}
	else
		i += print_char(arg + 48, output);
	return (i);
}
