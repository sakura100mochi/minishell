/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:05:35 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/11/11 16:40:10 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

char	*ft_command(char **one_phrase, t_parser *node)
{
	size_t	i;
	char	*cmd;

	cmd = NULL;
	i = 0;
	while (one_phrase[i] != NULL)
	{
		if ((one_phrase[i][0] == '<' || one_phrase[i][0] == '>') &&
				one_phrase[i + 1] != NULL &&
				(one_phrase[i + 1][0] == '<' || one_phrase[i + 1][0] == '>'))
			i += 2;
		else if (one_phrase[i][0] == '<' || one_phrase[i][0] == '>')
			i++;
		else if (i == 1 && one_phrase[1][0] == '-')
		{
			while (one_phrase[i] != NULL && one_phrase[i][0] == '-')
				i++;
		}
		if (one_phrase[i] != NULL)
			cmd = ft_command_add(cmd, one_phrase[i], node);
		if (one_phrase[i] != NULL)
			i++;
	}
	return (cmd);
}

char	*ft_command_add(char *cmd, char *one_phrase, t_parser *node)
{
	char	*tmp;

	tmp = cmd;
	cmd = ft_strjoin_minis(cmd, one_phrase, node);
	if (tmp != NULL)
		free(tmp);
	return (cmd);
}

char	*ft_option(char **one_phrase, t_parser *node)
{
	size_t	i;
	char	*option;
	char	*tmp;

	i = 1;
	option = NULL;
	if (one_phrase[1] != NULL && one_phrase[1][0] == '-')
	{
		while (one_phrase[i] != NULL && one_phrase[i][0] == '-')
		{
			if (option == NULL)
				option = ft_strjoin_minis(NULL, one_phrase[i], node);
			else
			{
				tmp = option;
				option = ft_strjoin_minis(option, one_phrase[i], node);
				if (tmp != NULL)
					free(tmp);
			}
			i++;
		}
	}
	return (option);
}

t_file	*ft_redirect(char **one_phrase, t_parser *node)
{
	size_t	i;
	t_file	*file;
	t_file	*new;

	i = 0;
	file = NULL;
	while (one_phrase[i] != NULL)
	{
		if (one_phrase[i][0] == '<' || one_phrase[i][0] == '>')
		{
			new = ft_filenew(&one_phrase[i], node);
			if (new == NULL)
				return (NULL);
			ft_fileadd_back(&file, new);
			while (one_phrase[i] != NULL && \
				(one_phrase[i][0] == '<' || one_phrase[i][0] == '>'))
				i++;
		}
		if (one_phrase[i] != NULL)
			i++;
	}
	return (file);
}

char	*ft_all(char *prompt, size_t *k)
{
	size_t	i;
	size_t	j;
	char	*all;

	i = *k;
	while (prompt[i] == '|')
		i++;
	j = i;
	while (prompt[j] != '\0' && prompt[j] != '|')
		j++;
	all = ft_substr(prompt, i, j - i);
	*k = j;
	return (all);
}
