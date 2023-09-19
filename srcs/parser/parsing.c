/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:26:19 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/19 20:07:21 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*parsing(t_parser *parse, char **phrase)
{
	parse = ft_calloc(sizeof(t_parser), 1);
	if (parse == NULL)
		return ((t_parser *)MALLOC_ERROR);
	parse = command(parse, phrase);
	return (parse);
}

t_parser	*command(t_parser *parse, char **phrase)
{
	size_t	i;

	i = 0;
	while (check_command(phrase[i]) == NO && phrase[i] != NULL)
		i++;
	if (phrase[i] == NULL)
		return ((t_parser *)NO_COMMAND);
	parse->cmd = phrase[i];
	i = 0;
	while (phrase[i] != NULL)
	{
		printf("[%s]\n", phrase[i]);
		if (phrase[i][0] == '-')
		{
			if (parse->option == NULL)
				parse->option = phrase[i];
			else
				ft_strlcat(parse->option, phrase[i],
					ft_strlen(parse->option) + ft_strlen(phrase[i]) + 1);
			printf("***%s\n", parse->option);
		}
		i++;
	}
	return (parse);
}

int	check_command(char *str)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (YES);
	if (ft_strncmp(str, "cd", 3) == 0)
		return (YES);
	if (ft_strncmp(str, "pwd", 4) == 0)
		return (YES);
	if (ft_strncmp(str, "export", 7) == 0)
		return (YES);
	if (ft_strncmp(str, "unset", 6) == 0)
		return (YES);
	if (ft_strncmp(str, "env", 4) == 0)
		return (YES);
	if (ft_strncmp(str, "exit", 5) == 0)
		return (YES);
	if (ft_strncmp(str, "cat", 4) == 0)
		return (YES);
	return (NO);
}
