/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:05:35 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/20 22:23:38 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_command(char **one_phrase)
{
	size_t	i;

	i = 0;
	while (check_command(one_phrase[i]) == NO && one_phrase[i] != NULL)
		i++;
	if (one_phrase[i] == NULL)
		return (NULL);
	return (one_phrase[i]);
}

char	*ft_option(char **one_phrase)
{
	size_t	i;
	char	*option;

	i = 0;
	option = NULL;
	while (one_phrase[i] != NULL)
	{
		if (one_phrase[i][0] == '-')
		{
			if (option == NULL)
				option = one_phrase[i];
			else
				ft_strlcat(option, one_phrase[i],
					ft_strlen(option) + ft_strlen(one_phrase[i]) + 1);
		}
		i++;
	}
	return (option);
}

char	*ft_str(char **one_phrase)
{
	(void)one_phrase;
	return (NULL);
}

t_file	*ft_redirect(char **one_phrase)
{
	(void)one_phrase;
	return (NULL);
}