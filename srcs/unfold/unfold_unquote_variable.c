/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_unquote_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:14:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/16 22:13:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static char	*trim_unquote_str(char *str, size_t start)
{
	char	*result;
	size_t	index;

	index = start;
	while (str[index] != '\0')
	{
		if (str[index] == '\'' || str[index] == '"')
			break ;
		index++;
	}
	result = ft_substr(str, start, index - 1);
	return (result);
}

char	*unfold_str(char *str, t_env *env, size_t *start)
{
	size_t	len;
	size_t	index;
	char	*tmp;
	char	**strage;
	char	*result;

	index = 0;
	result = NULL;
	tmp = trim_unquote_str(str, *start);
	len = cnt_env_variable(tmp);
	strage = split_env_variable(tmp, len);
	// for (int i = 0; strage[i] != NULL; i++)
	// 	printf("|%s|, tmp:%s\n", strage[i], tmp);
	unfold_split_words(strage, env);
	while (strage[index] != NULL)
	{
		result = strjoin_mini(result, strage[index]);
		index++;
	}
	len = *start + ft_strlen(tmp);
	result = str_connection(result, str, start, &len);
	free(str);
	free(tmp);
	double_array_free(strage);
	return (result);
}
