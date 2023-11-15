/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:34:38 by wamonvor          #+#    #+#             */
/*   Updated: 2023/11/06 16:47:53 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <termios.h>

void	sigint_handler2(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_signals(int i)
{
	struct sigaction	sa;
	struct termios		term;
	char				*shlvl_str;

	shlvl_str = getenv("SHLVL");
	if (atoi(shlvl_str) == 1)
	{
		if (i == 1)
			sa.sa_handler = sigint_handler;
		else
			sa.sa_handler = sigint_handler2;
	}
	else
		sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
}

void	init_signals2(void)
{
	struct sigaction	sa;
	struct termios		term;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
}

void	init_signals3(void)
{
	struct sigaction	sa;
	struct termios		term;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	sa.sa_handler = sigint_handler3;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
}
//rl_crlf();
// void	init_signals(void)
// {
//
// 	struct sigaction	sa;
// 	struct termios		term;
// 	char				*shlvl_str;

// 	shlvl_str = getenv("SHLVL");
// 	if (atoi(shlvl_str) == 1)
// 		sa.sa_handler = sigint_handler;
// 	else
// 		sa.sa_handler = SIG_IGN;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = SA_RESTART;
// 	sigaction(SIGINT, &sa, NULL);
// 	tcgetattr(STDIN_FILENO, &term);
// 	term.c_lflag &= ~(ICANON | ECHOCTL);
// 	// tcsetattr(STDIN_FILENO, TCSANOW, &term);
// 	// sa.sa_handler = SIG_IGN;
// 	// sigemptyset(&sa.sa_mask);
// 	// sa.sa_flags = SA_RESTART;
// 	// sigaction(SIGQUIT, &sa, NULL);
// }
//
//  Ctr-Cnot show C prompt
//  #include <termios.h>
//
// void init_signals(void)
// {
//     struct sigaction sa;
//
//     sa.sa_handler = sigint_handler;
//     sa.sa_flags = 0;
//     sigemptyset(&sa.sa_mask);
//     sigaction(SIGINT, &sa, NULL);
//
//     struct termios term;
//     tcgetattr(STDIN_FILENO, &term);
//     term.c_lflag &= ~(ICANON | ECHOCTL);
//     tcsetattr(STDIN_FILENO, TCSANOW, &term);
//     sa.sa_handler = SIG_IGN;
//     sa.sa_flags = 0;
//     sigemptyset(&sa.sa_mask);
//     sigaction(SIGQUIT, &sa, NULL);
// }
// #include <stdio.h>
// #include <signal.h>
// #include <stdlib.h>
// #include <unistd.h>
//
// typedef struct {
//     int some_data;
// } SignalData;
//
// void sigint_handler(int sig) {
//     SignalData data;
//     // Read data from the pipe
//     if (read(pipe_fd[0], &data, sizeof(data)) == -1) {
//         perror("read");
//         exit(1);
//     }
//
//     if (data.some_data == 2) {
//         printf("Handling SIGINT with additional data %d\n", data.some_data);
//         // Add your handling code here
//     }
// }
//
// int pipe_fd[2];
//
// void init_signals(int shlvl) {
//     struct sigaction sa;
//     SignalData data;
//     data.some_data = shlvl;
//
//     // Create a pipe for communication
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe");
//         exit(1);
//     }
//
//     sa.sa_handler = sigint_handler;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = SA_RESTART;
//     sigaction(SIGINT, &sa, NULL);
//
//     sa.sa_handler = SIG_IGN;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = SA_RESTART;
//     sigaction(SIGQUIT, &sa, NULL);
//
//     // Send the additional data through the pipe
//     if (write(pipe_fd[1], &data, sizeof(data)) == -1) {
//         perror("write");
//         exit(1);
//     }
// }
//
// int main() {
//     init_signals(2); // Set the value of shlvl
//     // Your main program logic here
//     while (1) {
//         // Do some work
//     }
//     return 0;
// }
//
//
// void	sigint_handler(int sig)
// {
// 	(void)sig;
// 		rl_crlf(); 
//     rl_on_new_line();
//     rl_replace_line("", 0);
//     rl_redisplay();
// }
//
// void	init_signals()
// {
// 	struct sigaction	sa;
// 	char *shlvl_str;
// 	shlvl_str = getenv("SHLVL");
// 	if (atoi(shlvl_str) == 1)
// 	{
// 	sa.sa_handler = sigint_handler;
// 	//sa.sa_handler = SIG_IGN;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = SA_RESTART;
// 	sigaction(SIGINT, &sa, NULL);
// 	}
// 	else
// 	{
// 	sa.sa_handler = SIG_IGN;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = SA_RESTART;
// 	sigaction(SIGINT, &sa, NULL);
// 	}
// 	sa.sa_handler = SIG_IGN;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = SA_RESTART ;
// 	sigaction(SIGQUIT, &sa, NULL);
// }