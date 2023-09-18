/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:26:19 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/18 16:43:29 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*parsing(t_parser *parse, char **phrase)
{
	size_t		i;

	i = 0;
	while (check_command(phrase[i]) == YES && phrase[i] != NULL)
	{
		printf("***%s\n", phrase[i]);
		i++;
	}
	if (phrase[i] == NULL)
		return ((t_parser *)NO_COMMAND);
	parse->command = phrase[i];
	printf("%ld_____command_____%s\n", i, phrase[i - 1]);
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
	return (NO);
}
