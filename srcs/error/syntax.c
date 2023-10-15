/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/15 21:51:56 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

int	syntax(void)
{
	ft_printf("minishell: syntax error\n");
	return (NO);
}

int	redirect_syntax(t_data *data, char *str)
{
	size_t		i;
	t_parser	*node;
	t_file		*file;

	i = 0;
	node = data->parser;
	file = node->redirect;
	while (str[i] != '\0' && node != NULL)
	{
		if (file == NULL)
		{
			node = node->next;
			file = node->redirect;
			continue ;
		}
		else if (file->type == HEREDOC || file->type == QUOTE_HEREDOC)
		{
			while (str[i] != '<' && str[i] != '\0')
				i++;
			if (str[i] != '\0' && str[i] == '<' && str[i + 1] != '\0' && str[i + 1] != '<')
				return (NO);
			else if (file->next != NULL)
				file = file->next;
			i++;
		}
		else if (file->type == APPEND)
		{
			while (str[i] != '>' && str[i] != '\0')
				i++;
			if (str[i] != '\0' && str[i] == '>' && str[i + 1] != '\0' && str[i + 1] != '>')
				return (NO);g
			else if (file->next != NULL)
				file = file->next;
			i++;
		}
		if (str[i] == '|')
		{
			node = node->next;
			file = node->redirect;
		}
		i++;
	}
	return (YES);
}
