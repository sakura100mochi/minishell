/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:51:23 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/08 17:08:54 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ctrl+c : SIGINT
//ctrl+\ : SIGQUIT

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	exit(EXIT_SUCCESS);
	(void)signum;
	(void)dummy;
	(void)info;
	return ;
}

void	signal_heredoc(t_signal *signal)
{
	signal->act1.sa_sigaction = signal_handler;
	sigemptyset(&signal->act1.sa_mask);
	signal->act1.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &signal->act1, NULL);

	signal->act2.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signal->act2, NULL);
	return ;
}
