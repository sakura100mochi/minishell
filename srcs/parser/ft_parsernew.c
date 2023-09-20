/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsernew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:36 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/20 22:48:42 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*ft_parsernew(char *cmd, char *option, char *str, t_file *redirect)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (node == NULL)
		return (NULL);
	node->cmd = cmd;
	node->option = option;
	node->str = str;
	node->redirect = redirect;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
