/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/14 18:25:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_data	*data;

	data = NULL;
	data = init_minishell(data);
	signal_minishell(data->signal);
	standby_state(data);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }
