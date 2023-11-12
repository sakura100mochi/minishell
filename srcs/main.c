/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/12 16:28:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

volatile sig_atomic_t g_signal;

int	main(void)
{
	t_data	*data;

	data = NULL;
	data = init_minishell(data);
	signal_minishell(data->signal, NORMAL);
	standby_state(data);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }
