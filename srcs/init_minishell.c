/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/19 19:08:34 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_init	*init_minishell(t_init *state)
{
	t_exe		*exe_built;
	t_signal	*sig_act;
	t_error		*error;

	state = (t_init *)ft_calloc(sizeof(t_init), 1);
	exe_built = (t_exe *)ft_calloc(sizeof(t_exe), 1);
	sig_act = (t_signal *)ft_calloc(sizeof(t_signal), 1);
	error = (t_error *)ft_calloc(sizeof(t_error), 1);
	state = init_env(state);
	state->exe = exe_built;
	state->signal = sig_act;
	state->error = error;
	return (state);
}

	// ft_memset(state, 0, sizeof(t_init));
	// ft_memset(exe_built, 0, sizeof(t_exe));
	// ft_memset(sig_act, 0, sizeof(t_signal));