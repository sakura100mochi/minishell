/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_quote_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:59:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/03 15:13:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static int	check_env_variable(char *str, size_t start, size_t end)
{
	size_t	index;

	index = start;
	while (index < end)
	{
		if (str[index] == '$')
			return (0);
		index++;
	}
	return (1);
}

char	*unfold_quote_variable(char *str, size_t start, size_t end)
{
	if (check_env_variable(str, start, end))
	return (str);
	return (NULL);
}