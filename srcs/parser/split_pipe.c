/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:07:28 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/20 22:27:27 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*split_pipe(char **str, char **one_phrase)
{
	t_parser	*new;
	t_parser	*node;
	size_t	i;
	size_t	j;

	i = 0;
	node = NULL;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i] != NULL && str[i][0] != '|')
		{
			one_phrase[j] = str[i];
			i++;
			j++;
		}
		new = ft_parsernew(ft_command(one_phrase), ft_option(one_phrase),
			ft_str(one_phrase), ft_redirect(one_phrase));
		ft_parseradd_back(&node, new);
		if (str[i] != NULL)
			i++;
		ft_bzero_double(one_phrase);
	}
	return (node);
}
