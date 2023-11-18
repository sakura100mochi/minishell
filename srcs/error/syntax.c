/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/18 15:21:38 by yhirai           ###   ########.fr       */
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
		j += 2;
	else
		return (NO);
	*i = j;
	if (all[j - 2] == c && all[j - 1] == c)
		return (YES);
	return (NO);
}

static void	when_output_input(char *all, size_t *i)
{
	size_t	j;

	j = *i;
	while (all[j] != '\0'
		&& all[j] != '<' && all[j] != '>')
		j++;
	if (all[j] == '<' || all[j] == '>')
		j++;
	*i = j;
}

static int	redirecyt_utils(t_parser *node, t_file *file, size_t *i)
{
	if (file->type == HEREDOC || file->type == Q_H)
	{
		if (check_redirect(node->all, i, '<') == NO)
			return (NO);
	}
	else if (file->type == APPEND)
	{
		if (check_redirect(node->all, i, '>') == NO)
			return (NO);
	}
	else
		when_output_input(node->all, i);
	return (YES);
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
			if (redirecyt_utils(node, file, &i) == NO)
				return (NO);
			file = file->next;
		}
		node = node->next;
	}
	return (YES);
}
