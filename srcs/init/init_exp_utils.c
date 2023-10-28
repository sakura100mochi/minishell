/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/29 04:10:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

t_exp	*new_exp_node(char *content, size_t head)
{
	t_exp	*new;

	new = (t_exp *)ft_calloc(1, sizeof(t_exp));
	if (!new)
		return (NULL);
	if (head)
		new -> head = 1;
	new -> variable = content;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}
