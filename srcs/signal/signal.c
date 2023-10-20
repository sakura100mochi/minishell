/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/20 14:48:36 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ctrl+c : SIGINT
//ctrl+\ : SIGQUIT

static void	normal_sigint(int signum)
{
	(void)signum;
	printf("---normal_sigint---\n");
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	return ;
}

void	signal_minishell(t_signal *sig, int flag)
{
	if (flag == NORMAL)
	{
		sig->act1.sa_handler = normal_sigint;
		sigemptyset(&sig->act1.sa_mask);
		sig->act1.sa_flags = 0;
		sigaction(SIGINT, &sig->act1, NULL);
	
		sig->act2.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &sig->act2, NULL);
	}
	else if (flag == REDIRECT)
		signal_heredoc(sig);
	else if (flag == INTERACTIVE)
		signal_interactive(sig);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	return ;
}
