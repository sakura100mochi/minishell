/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/17 19:53:09 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(t_init *state)
{
	t_exe		*exe_built;
	t_signal	*sig_act;

	state = (t_init *)ft_calloc(sizeof(t_init), 1);
	exe_built = (t_exe *)ft_calloc(sizeof(t_exe), 1);
	sig_act = (t_signal *)ft_calloc(sizeof(t_signal), 1);
	state->exe = exe_built;
	state->signal = sig_act;
	printf("%p, %p\n", exe_built, sig_act);
	return ;
}

	// ft_memset(state, 0, sizeof(t_init));
	// ft_memset(exe_built, 0, sizeof(t_exe));
	// ft_memset(sig_act, 0, sizeof(t_signal));