/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:21:14 by wamonvor          #+#    #+#             */
/*   Updated: 2023/03/13 13:00:47 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}
	return (num * sign);
}

/**
Function converts a string to an integer.

The function takes a single argument, a pointer to a character 
string s that represents the number to be converted.

The function works by first skipping any whitespace characters at 
the beginning of the string. It then checks for 
a sign character (+ or -) 
and adjusts the sign of the final integer accordingly. 
The function then iterates 
through the string, converting each digit to an integer 
and adding it to the total.

int	ft_atoi(const char *s)
{
	int	i;       // declare i as type integer use for positioning in argument (*s) 
	int	sign;    // declare Sign for keep negative(-) or positive (+) number  
	int	num;     // use for keep the result

	i = 0;
	sign = 1;
	num = 0;

	// Skip any leading whitespace characters
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;

	// Check for a sign character and adjust the sign of the final integer
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
			sign *= -1;
		i++;
	}

	// Iterate through the string, converting each digit to an integer
	// and adding it to the total
	while (s[i] >= 48 && s[i] <= 57)
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}

	// Multiply the final integer by the sign and return it
	// ** It will be have some error when num is > max(2147483647)
	// or num < min(-2147483648)
	return (num * sign);
}

**/
