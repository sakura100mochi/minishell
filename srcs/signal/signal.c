/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/08 19:52:43 by yhirai           ###   ########.fr       */
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
		ft_printf("\n");
		rl_replace_line("", 0);
	}
	else
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	signal_minishell(t_signal *signal)
{
	signal->act1.sa_sigaction = signal_handler;
	sigemptyset(&signal->act1.sa_mask);
	signal->act1.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &signal->act1, NULL);

	signal->act2.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signal->act2, NULL);
	return ;
}
