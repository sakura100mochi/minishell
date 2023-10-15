/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:02:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/15 17:57:45 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static size_t	count_char(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		return (1);
	while (str[i] != ' ' && str[i] != '|' && str[i] != '<'
		&& str[i] != '>' && str[i] != '\0')
		i++;
	return (i);
}

char	*split_word(char **str)
{
	char	*result;
	char	*tmp;
	size_t	len;
	size_t	i;

	tmp = *str;
	i = 0;
	while ((tmp[i] == ' ' && tmp[i] != '\0')
		|| (tmp[i] == '	' && tmp[i] != '\0'))
		i++;
	len = count_char(&tmp[i]);
	result = ft_substr(&tmp[i], 0, len);
	while ((tmp[len + i] == ' ' && tmp[len + i] != '\0')
		|| (tmp[len + i] == '	' && tmp[len + i] != '\0'))
		len++;
	*str += len + i;
	return (result);
}
