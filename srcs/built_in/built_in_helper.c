/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:42:14 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 19:42:45 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

t_env	*serch_env_variable(t_env *head, char *variable)
{
	size_t	len;
	t_env	*serch_variable;

	serch_variable = head;
	if (*variable == '\0')
		return (serch_variable->prev);
	serch_variable = serch_variable->next;
	len = ft_strlen(variable);
	while (!serch_variable->head)
	{
		if (!ft_strncmp(serch_variable->variable, variable, len))
			break ;
		serch_variable = serch_variable->next;
	}
	return (serch_variable);
}
