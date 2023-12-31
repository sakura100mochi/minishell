/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/13 12:29:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

int	check_env_variable(char *str, size_t start, size_t end)
{
	size_t	index;

	index = start;
	while (index < end && str[index] != '\"')
	{
		if (str[index] == '$')
			return (0);
		index++;
	}
	return (1);
}

size_t	check_dollar_charactor(const char *str, size_t index)
{
	if (str[index] == '$' && (str[index + 1] == '?' || \
								ft_isalnum(str[index + 1])))
		return (YES);
	return (NO);
}

char	*str_connection(char *result, char *str, size_t *start, size_t *end)
{
	char	*tmp_f;
	char	*tmp_b;
	char	*tmp;

	tmp_f = ft_substr(str, 0, *start);
	tmp_b = ft_substr(str, *end, ft_strlen(str) - *end);
	tmp = ft_strjoin(tmp_f, result);
	*end = ft_strlen(tmp);
	*start = ft_strlen(tmp);
	free(result);
	result = ft_strjoin(tmp, tmp_b);
	free(tmp_f);
	free(tmp_b);
	free(tmp);
	return (result);
}

size_t	cnt_env_variable(char *str)
{
	size_t	index;
	size_t	nbr;

	index = 0;
	nbr = 0;
	while (str[index] != '\0')
	{
		if (check_dollar_charactor(str, index))
		{
			nbr++;
			index++;
		}
		index++;
	}
	return (nbr * 2 + 1);
}

char	*unfold_main(t_env *env, char *str)
{
	str = check_quote_in_str(str, env);
	return (str);
}
