/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:38:17 by wichitt           #+#    #+#             */
/*   Updated: 2023/11/06 16:49:11 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define READLINE_MSG	"minishell $ "
# include "../src/libft/libft.h"
# include "execution.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "parser.h"
# include <signal.h>
# include <stddef.h>

//========envp==============//
char			**ft_dupenvp(char **arr);
char			*find_path(char **envp);

// void	free_arr(char **split_arr);

//======signel===============//
void			sigquit_handler(int sig);
void			init_signals(int i);
void			ctrl_d_handler(int sig, siginfo_t *info, void *ucontext);

//======peaser==============//
int				count_quotes(char *line);
int				parse_envp(t_tools *tools);
int				nit_tools(t_tools *tools);
t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools);
t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools);
t_simple_cmds	*ft_simple_cmdsnew(char **str,
					int num_redirections, t_lexer *redirections);
int				find_matching_quote(char *line, int i, int *num_del, int del);
void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);
int				find_pwd(t_tools *tools);

//=======lexer===============//
int				token_reader(t_tools *tools);
int				handle_token(char *str, int i, t_lexer **lexer_list);
t_tokens		check_token(int c);
int				is_whitespace(char c);
int				skip_spaces(char *str, int i);
int				add_node(char *str, t_tokens token, t_lexer **lexer_list);
int				read_words(int i, char *str, t_lexer **lexer_list);
int				handle_quotes(int i, char *str, char del);
void			ft_lexerdelone(t_lexer **lst, int key);
void			ft_lexerdel_first(t_lexer **lst);
t_lexer			*ft_lexerclear_one(t_lexer **lst);
void			ft_lexerclear(t_lexer **lst);
t_lexer			*ft_lexernew(char *str, int token);
void			ft_lexeradd_back(t_lexer **lst, t_lexer *new);

//==========exec=================//
int				start_executor(t_tools *tools);

//========main===============//
int				loopshell(t_tools *tools);
int				restart_shell(t_tools *tools);
int				restart_shellcmd(t_cmds *cmds, t_envs *env, int *ret, char **a);
void			loopshellcmds(t_cmds *ls_cmds, t_envs *env, int *ret);

//==========error===============//
//int	ft_error(int error);
void			ft_error(char *error_msg);
int				printdata(t_cmds *ls_cmds);
int				split_input(const char *input, char *tokens[], int max_tokens);
char			**tokenize_input(char *input);
int				is_singlecomand(t_cmds *ls_cmds);
bool			is_onstr(const char *str, int ch);
bool			is_spaces(char c);
size_t			get_token_len(char *input_at_i);
size_t			get_nr_statements(char *input);
char			**parse_input(char *input, size_t i, size_t k);
int				printchararray(char *input);
int				print2chararray(char **input);
char			*remove_quotes(char	*parsed, size_t i, size_t j);
size_t			remove_quotes_size(char	*parsed);
void			is_print(t_print *t_print, char str);
int				init_expan(t_print *myprint);
int				ls_cmdsinit(t_cmds **ls_cmds, t_envs *env);
bool			contains_only_whitespace(const char *input);
void			free_envsx(t_envs *envs);
void			free_cmds_list(t_cmds *head);
int				loop_for_dollar_sign(t_cmds *cmds, char *st, char **tm, int i);
int				exit_fatal_message(t_cmds *ls_cmds, char *str, int exitstatus);
void			miniloop(t_cmds *ls_cmds, t_envs *env, int *ret, char *argg);
size_t			get_nr_s(char *input, bool flag, bool quotes, size_t count);
int				executeCommandsConcurrently(t_cmds *commands);
int				incrementshlvl(t_envs *envs);

//==========ft_error.c===============//
int				Check_Unex_Token(t_cmds *ls_cmds);
int				dir_error(char *error_message);
int				exec_cmd2(t_cmds *c, char *path, t_envs	*ptr_envs);
int				countarraysize(char **str);
bool			is_operator(char *str);
bool			is_valid_sequence(char **std, int i, int max);
int				functioncheck(char **a);
void			checkcmd_lexer(int type);
void			tokencheck(char **a, t_cmds *ls_cmds, t_envs *env);
void			sigint_handler2(int sig);
void			sigint_handler3(int sig);
void			sigint_handler(int sig);
char			*creat_aleatori_name(void);
int				aleatori_char(void);
int				create_heredoc_fd(t_cmds *cmdl);
int				write_in_fd(int fd, char *limitor, bool expanded);
char			*expand_variable2(char *str);
void			init_signals2(void);
void			init_signals3(void);
size_t			pipe_sign(char *str);
#endif
