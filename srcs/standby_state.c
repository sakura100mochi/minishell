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

void	standby_state(t_data *data)
{
	while (1)
	{
		data->prompt = readline("minishell$");
		add_history(data->prompt);
		if (!*(data)->prompt)
		{
			free(data->prompt);
			continue ;
		}
		else if (data->prompt[0] == EOF)
		{
			printf("^D\n");
			continue ;
		}
		data->parser = parser_main(lexer_main(data->prompt));
		execution_main(data);
		free(data->prompt);
	}
	return ;
}
