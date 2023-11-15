/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:44:53 by wichitt           #+#    #+#             */
/*   Updated: 2023/10/23 10:36:54 by wichitt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**parse_input(char *input, size_t i, size_t k)
{
	char		**parsed;
	size_t		len;
	size_t		j;

	parsed = malloc((get_nr_s(input, false, false, 0) + 1) * sizeof(char *));
	while (input[i])
	{
		len = get_token_len(&input[i]);
		if (!len)
		{
			i += 1;
			continue ;
		}
		parsed[k] = malloc((len + 1) * sizeof(char *));
		j = 0;
		while (input[i] && j < len)
			parsed[k][j++] = input[i++];
		parsed[k++][j] = '\0';
	}
	parsed[k] = NULL;
	return (parsed);
}

void	manage_quotes(char *input, bool *quotes, char *quote_char)
{
	if (*quotes)
	{
		if (*input == *quote_char)
		{
			*quotes = false;
			*quote_char = 0;
		}
	}
	else
	{
		*quotes = true;
		*quote_char = *input;
	}
}

size_t	get_nr_s(char *input, bool flag, bool quotes, size_t count)
{
	char	quote_char;

	quote_char = 0;
	while (*input)
	{
		if (is_onstr(OPERATORS, *input))
			count += 1;
		if (is_onstr(QUOTES, *input))
			manage_quotes(input, &quotes, &quote_char);
		if (*input != ' ' && !is_onstr(OPERATORS, *input) && !flag && !quotes)
		{
			flag = true;
			count += 1;
		}
		else if (*input == ' ' || is_onstr(OPERATORS, *input))
			flag = false;
		input += 1;
	}
	return (count);
}

size_t	get_token_len(char *input_at_i)
{
	size_t	i;
	char	quotes;

	i = 0;
	if (is_onstr(OPERATORS, input_at_i[i]))
	{
		if (input_at_i[i] == input_at_i[i + 1])
			return (2);
		return (1);
	}
	while (input_at_i[i]
		&& !is_spaces(input_at_i[i])
		&& !is_onstr(OPERATORS, input_at_i[i]))
	{
		if (is_onstr(QUOTES, input_at_i[i]))
		{
			quotes = input_at_i[i++];
			while (input_at_i[i] && input_at_i[i] != quotes)
				i += 1;
		}
		i += 1;
	}
	return (i);
}

bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

// size_t	get_nr_s(char *input, bool flag, bool quotes, size_t count)
// {
// 	char	quote_char;
//
// 	quote_char = 0;
// 	while (*input)
// 	{
// 		if (is_onstr(OPERATORS, *input))
// 			count += 1;
// 		if (is_onstr(QUOTES, *input))
// 		{
// 			if (quotes)
// 			{
// 				if (*input == quote_char)
// 				{
// 					quotes = false;
// 					quote_char = 0;
// 				}
// 			}
// 			else
// 			{
// 				quotes = true;
// 				quote_char = *input;
// 			}
// 		}
// 		if (*input != ' ' && !is_onstr(OPERATORS, *input) && !flag && !quotes)
// 		{
// 			flag = true;
// 			count += 1;
// 		}
// 		else if (*input == ' ' || is_onstr(OPERATORS, *input))
// 			flag = false;
// 		input += 1;
// 	}
// 	return (count);
// }
//
//
//parsed = malloc((get_nr_statements(input) + 1) * sizeof(char *));
// size_t get_nr_statements(char *input)
// {
//     size_t count = 0;
//     bool flag = false;
//     bool quotes = false;
//     char quote_char = 0;
//
//     while (*input) {
//         if (is_onstr(OPERATORS, *input))
//             count += 1;
//         if (is_onstr(QUOTES, *input)) {
//             if (quotes) {
//                 if (*input == quote_char) {
//                     quotes = false;
//                     quote_char = 0;
//                 }
//             } else {
//                 quotes = true;
//                 quote_char = *input;
//             }
//         }
//if (*input != ' ' && !is_onstr(OPERATORS, *input) && !flag && !quotes) {
//             flag = true;
//             count += 1;
//         } else if (*input == ' ' || is_onstr(OPERATORS, *input)) {
//             flag = false;
//         }
//         input += 1;
//     }
//     return count;
// }
//
//
// size_t	get_nr_statements(char *input)
// {
// 	size_t	count;
// 	bool	flag;
// 	bool	quotes;
//
// 	count = 0;
// 	flag = false;
// 	quotes = false;
// 	while (*input)
// 	{
// 		if (is_onstr(OPERATORS, *input))
// 			count += 1;
// 		if (is_onstr(QUOTES, *input) && *input == *(input + 1))
// 			input += 1;
// 		else if (is_onstr(QUOTES, *input))
// 			quotes = !quotes;
// 		if (*input != ' ' && !is_onstr(OPERATORS, *input) && !flag && !quotes)
// 		{
// 			flag = true;
// 			count += 1;
// 		}
// 		else if (*input == ' ' || is_onstr(OPERATORS, *input))
// 			flag = false;
// 		input += 1;
// 	}
// 	return (count);
// }