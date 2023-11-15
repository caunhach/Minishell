/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2015 <macbookpro2015@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:58:47 by caunhach          #+#    #+#             */
/*   Updated: 2023/10/27 20:32:05 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_heredoc(t_cmds *ls_cmds, char *filename)
{
	t_lexers	*heredoc;
	char		*line;
	int			fd;

	heredoc = ls_cmds->ls_lexers;
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline("> ");
	while (line && ft_strncmp(heredoc->str, line, ft_strlen(line)))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_heredoc(t_cmds *ls_cmds, t_lexers *heredoc, char *file_name)
{
	int			exit_status;

	exit_status = EXIT_SUCCESS;
	delete_quotes(heredoc->str, '\"');
	delete_quotes(heredoc->str, '\'');
	exit_status = exec_heredoc(ls_cmds, file_name);
	return (exit_status);
}

char	*generate_hd_filename(void)
{
	static int	i;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	heredoc_main(t_cmds *ls_cmds)
{
	t_lexers	*head;

	head = ls_cmds->ls_lexers;
	while (ls_cmds->ls_lexers)
	{
		if (ls_cmds->ls_lexers->types == LESS_LESS)
		{
			if (ls_cmds->hd_filename)
				free(ls_cmds->hd_filename);
			ls_cmds->hd_filename = generate_hd_filename();
			ft_heredoc(ls_cmds, ls_cmds->ls_lexers, ls_cmds->hd_filename);
		}
		ls_cmds->ls_lexers = ls_cmds->ls_lexers->next;
	}
	ls_cmds->ls_lexers = head;
	return (EXIT_SUCCESS);
}
