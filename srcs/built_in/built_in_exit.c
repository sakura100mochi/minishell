/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 14:58:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_exit(t_init *state)
{
	free(state->prompt);
	delete_all_env_node(state->env);
	exit(EXIT_SUCCESS);
	return ;
}
