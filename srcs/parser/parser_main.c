/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 13:39:16 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*parser_main(char **str)
{
	
}

int	main(void)
{
	char	**result;
	char	str[] = "echo 'orld' \"hello\" cat < file | ";
	int		i;

	result = lexer_main(str);
	i = 0;
	while (result[i] != '\0')
	{
		printf("lexer : [%s]\n", result[i]);
		i++;
	}
	parser_main(lexer_main);
	ft_free(result);
	return (0);
}
