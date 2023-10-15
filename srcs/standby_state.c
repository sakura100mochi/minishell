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

void	standby_state(t_data *data)
{
	while (1)
	{
		data->prompt = readline("minishell$");
		if (data->prompt == NULL)
		{
			ft_printf("exit\n");
			exit(EXIT_SUCCESS);
		}
		if (*data->prompt == '\0')
		{
			free(data->prompt);
			continue ;
		}
		add_history(data->prompt);
		data->parser = parser_main(lexer_main(data->prompt));
		if (redirect_syntax(data, data->prompt) == NO)
			syntax();
		else if (data->parser->cmd == NULL && data->parser->redirect == NULL)
			syntax();
		else
			execution_main(data);
		free(data->prompt);
		parser_free(data->parser);
	}
	return ;
}
