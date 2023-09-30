/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:02:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 12:40:27 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	tmp = *str;
	len = count_char(tmp);
	result = ft_substr(tmp, 0, len);
	if (tmp[len] == ' ' && tmp[len] != '\0')
		len++;
	*str += len;
	return (result);
}
