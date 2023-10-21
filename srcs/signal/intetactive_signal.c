/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intetactive_signal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:44:30 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/10/21 16:51:05 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sigint(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	(void)signum;
}

static void	sigquit(int signum)
{
	write (STDOUT_FILENO, "Quit: 3\n", 8);
	(void)signum;
}

void	signal_interactive(t_signal *signal)
{
	signal->act1.sa_handler = sigint;
	sigemptyset(&signal->act1.sa_mask);
	signal->act1.sa_flags = 0;
	sigaction(SIGINT, &signal->act1, NULL);

	signal->act2.sa_handler = sigquit;
	sigemptyset(&signal->act2.sa_mask);
	signal->act2.sa_flags = 0;
	sigaction(SIGQUIT, &signal->act2, NULL);
	return ;
}
