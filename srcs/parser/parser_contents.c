/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:05:35 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/24 15:20:26 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_command(char **one_phrase)
{
	size_t	i;
	char	*cmd;

	cmd = NULL;
	i = 0;
	while (one_phrase[i] != NULL)
	{
		if ((one_phrase[i][0] == '<' || one_phrase[i][0] == '>') &&
				(one_phrase[i + 1][0] == '<' || one_phrase[i + 1][0] == '>'))
			i += 2;
		else if (one_phrase[i][0] == '<' || one_phrase[i][0] == '>')
			i++;
		else if (one_phrase[i][0] != '-')
			cmd = ft_command_add(cmd, one_phrase[i]);
		i++;
	}
	return (cmd);
}

char	*ft_command_add(char *cmd, char *one_phrase)
{
	char	*tmp;

	tmp = cmd;
	cmd = ft_strjoin_minis(cmd, one_phrase);
	if (tmp != NULL)
		free(tmp);
	return (cmd);
}

char	*ft_option(char **one_phrase)
{
	size_t	i;
	char	*option;
	char	*tmp;

	i = 0;
	option = NULL;
	while (one_phrase[i] != NULL)
	{
		if (one_phrase[i][0] == '-')
		{
			if (option == NULL)
				option = ft_strjoin_minis(NULL, one_phrase[i]);
			else
			{
				tmp = option;
				option = ft_strjoin_minis(option, one_phrase[i]);
				if (tmp != NULL)
					free(tmp);
			}
		}
		i++;
	}
	return (option);
}

t_file	*ft_redirect(char **one_phrase)
{
	size_t	i;
	t_file	*file;

	i = 0;
	file = NULL;
	while (one_phrase[i] != NULL)
	{
		if (one_phrase[i][0] == '<' || one_phrase[i][0] == '>')
		{
			ft_fileadd_back(&file, ft_filenew(&one_phrase[i]));
			if (one_phrase[i + 1][0] == '<' || one_phrase[i + 1][0] == '>')
				i++;
		}
		i++;
	}
	return (file);
}
