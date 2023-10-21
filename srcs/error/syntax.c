/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/21 14:49:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/error.h"

int	syntax(void)
{
	ft_printf("minishell: syntax error\n");
	return (NO);
}

static int	check_redirect(size_t *i, char *str, char c)
{
	int	j;

	j = *i;
	while (str[j] != c && str[j] != '\0')
		j++;
	if (str[j + 1] != '\0')
		j++;
	else
		return (NO);
	*i += j;
	if (str[j - 1] == c && str[j] == c)
		return (YES);
	return (NO);
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
			i++;
		while (file != NULL)
		{
			if (file->type == HEREDOC || file->type == QUOTE_HEREDOC)
			{
				if (check_redirect(&i, str, '<') == NO)
					return (NO);
				else
				{
					node = node->next;
					while (str[i] != '\0' && str[i] != '|')
						i++;
				}
			}
			else if (file->type == APPEND)
			{
				if (check_redirect(&i, str, '>') == NO)
					return (NO);
				else
				{
					node = node->next;
					while (str[i] != '\0' && str[i] != '|')
						i++;
				}
			}
			else
				i++;
			file = file->next;
		}
		if (str[i] == '|')
		{
			node = node->next;
			i++;
		}
	}
	return (YES);
}
