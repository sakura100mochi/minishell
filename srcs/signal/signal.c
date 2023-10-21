/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 05:27:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ctrl+c : SIGINT
//ctrl+\ : SIGQUIT

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	int		status;
	pid_t	pid;

	(void)signum;
	(void)dummy;
	(void)info;
	pid = wait(&status);
	if (pid != -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
	}
	else
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

static void	signal_handler_quit(int signum, siginfo_t *info, void *dummy)
{
	int		status;
	pid_t	pid;

	(void)signum;
	(void)dummy;
	(void)info;
	pid = wait(&status);
	if (pid != -1)
		write(STDOUT_FILENO, "Quit: 3\n", 8);
	else
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_minishell(t_signal *signal)
{
	signal->act1.sa_sigaction = signal_handler;
	sigemptyset(&signal->act1.sa_mask);
	signal->act1.sa_flags = 0;
	sigaction(SIGINT, &signal->act1, NULL);
	signal->act2.sa_sigaction = signal_handler_quit;
	sigemptyset(&signal->act2.sa_mask);
	signal->act2.sa_flags = 0;
	sigaction(SIGQUIT, &signal->act2, NULL);
	return ;
}
