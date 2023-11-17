/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:51:23 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/17 22:31:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sigint(int signum)
{
	g_signal = 1;
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
	(void)signum;
}

void	signal_heredoc(t_signal *signal)
{
	signal->act1.sa_handler = sigint;
	sigemptyset(&signal->act1.sa_mask);
	signal->act1.sa_flags = 0;
	sigaction(SIGINT, &signal->act1, NULL);
	signal->act2.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signal->act2, NULL);
	return ;
}
