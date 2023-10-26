/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/23 20:28:45 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

int	syntax(t_data *data)
{
	ft_printf("minishell: syntax error\n");
	data->env->status = 258;
	return (NO);
}

static int	check_redirect(char *all, size_t *i, char c)
{
	size_t	j;

	if (all == NULL)
		return (NO);
	j = *i;
	while (all[j] != '\0' && all[j] != c)
		j++;
	if (all[j + 1] != '\0')
		j++;
	else
		return (NO);
	*i += j;
	if (all[j - 1] == c && all[j] == c)
		return (YES);
	return (NO);
}

int	redirect_syntax(t_data *data)
{
	size_t		i;
	t_parser	*node;
	t_file		*file;

	node = data->parser;
	while (node != NULL)
	{
		i = 0;
		file = node->redirect;
		while (file != NULL)
		{
			if ((file->type == HEREDOC || file->type == Q_H)
				&& check_redirect(node->all, &i, '<') == NO)
				return (NO);
			else if ((file->type == APPEND)
				&& check_redirect(node->all, &i, '>') == NO)
				return (NO);
			file = file->next;
		}
		node = node->next;
	}
	data->env->status = 258;
	return (YES);
}
