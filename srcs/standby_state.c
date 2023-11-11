/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 17:30:58 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/pipe.h"
#include "../includes/error.h"

static int	syntax_check(t_data *data)
{
	t_parser	*node;
	t_file		*file;

	node = data->parser;
	while (node != NULL)
	{
		if (node->cmd == NULL && node->redirect == NULL)
			return (NO);
		file = node->redirect;
		while (file != NULL)
		{
			if (quote_check(file->file_name) == 2)
				return (NO);
			file = file->next;
		}
		node = node->next;
	}
	return (YES);
}

static int	judge_blank_space(char *prompt)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	while (prompt[index] != '\0')
	{
		if (prompt[index] != ' ' && prompt[index] != '	')
			flag = 1;
		index++;
	}
	if (flag)
		return (NO);
	free(prompt);
	return (YES);
}

static int	judge_readline(t_data *data)
{
	if (data->prompt == NULL)
	{
		ft_printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	if (*data->prompt == '\0')
	{
		free(data->prompt);
		return (YES);
	}
	if (judge_blank_space(data->prompt))
		return (YES);
	return (NO);
}

void	standby_state(t_data *data)
{
	while (1)
	{
		data->prompt = readline("minishell$");
		if (judge_readline(data))
			continue ;
		add_history(data->prompt);
		data->parser = parser_main(lexer_main(data->prompt), data->prompt);
		if (redirect_syntax(data) == NO || syntax_check(data) == NO)
			syntax(data);
		else if (data->parser == NULL)
		{
			free(data->prompt);
			continue ;
		}
		else
			execution_main(data);
		free(data->prompt);
		parser_free(data->parser);
	}
	return ;
}
