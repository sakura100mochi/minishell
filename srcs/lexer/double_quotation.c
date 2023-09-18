/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:39:31 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/18 12:12:26 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_char(char *str)
{
	size_t	i;

	i = 1;
	while (str[i] != '\"' && str[i] != '\0')
		i++;
	i++;
	return (i);
}

char	*double_quotation(char **str)
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
