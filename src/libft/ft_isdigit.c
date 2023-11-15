/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:20:59 by wamonvor          #+#    #+#             */
/*   Updated: 2023/10/10 23:40:24 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isdigitplus(int c)
{
	if ((c >= '0' && c <= '9') || (c == '-') || (c == '+'))
		return (1);
	else
		return (0);
}