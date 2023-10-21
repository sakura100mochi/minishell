/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/21 14:13:30 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

int	syntax(void)
{
	ft_printf("minishell: syntax error\n");
	return (NO);
}

static int	check_redirect(t_file *file, size_t *i, char *str, char c)
{
	int	j;

	j = *i;
	while (str[j] != c && str[j] != '\0')
		j++;
	if (str[j] != '\0' && str[j] == c && str[j + 1] != '\0' && str[j + 1] != c)
		return (NO);
	else if (file->next != NULL)
		file = file->next;
	j++;
	*i += j;
	return (YES);
}

int	redirect_syntax(t_data *data, char *str)
{
	size_t		i;
	t_parser	*node;
	t_file		*file;

	i = 0;
	node = data->parser;
	while (str[i] != '\0' && node != NULL)
	{
		file = node->redirect;
		if (file == NULL)
		{
			node = node->next;
			if (node != NULL)
				file = node->redirect;
			continue ;
		}
		else if ((file->type == HEREDOC || file->type == QUOTE_HEREDOC)
			&& check_redirect(file, &i, str, '<') == NO)
			return (NO);
		else if (file->type == APPEND
			&& check_redirect(file, &i, str, '>') == NO)
			return (NO);
		if (str[i] == '|')
			node = node->next;
		i++;
	}
	return (YES);
}
