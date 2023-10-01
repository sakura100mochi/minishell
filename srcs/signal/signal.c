/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/01 16:36:57 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	(void)dummy;
	(void)info;
	if (signum == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		// rl_replace_line("", 1);
		rl_redisplay();
		return ;
	}
	else if (signum == SIGQUIT)
		return ;
	return ;
}

void	signal_minishell(struct sigaction action)
{
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	return ;
}
