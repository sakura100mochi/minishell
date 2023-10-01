/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/01 17:05:27 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

static int	input_variable(t_env *env, char *str, char **strage)
{
	size_t	index;
	size_t	cnt;
	size_t	start;

	(void)env;
	index = 0;
	cnt = 0;
	start = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '$' && !start && (str[index] != ' ' || \
												str[index] != '	'))
			start = index + 1;
		else if (start && (str[index + 1] == ' ' || str[index + 1] == '	' || \
							str[index + 1] == '\0' || str[index + 1] == '$'))
		{
			strage[cnt++] = ft_substr(str, start, index - start + 1);
			start = 0;
		}
		index++;
	}
	strage[cnt] = NULL;
	return (0);
}

static char	*unfold_variable(t_env *env, char *str, size_t len)
{
	char	*result;
	char	**strage;

	(void)result;
	strage = (char **)ft_calloc(sizeof(char *), len + 1);
	input_variable(env, str, strage);
	for (int i = 0; strage[i] != NULL; i++)
		printf("%s\n", strage[i]);
	double_array_free(strage);
	return (NULL);
}

static size_t	find_env_variable(char *str)
{
	size_t	index;
	size_t	nbr;

	index = 0;
	nbr = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '$' && (str[index + 1] != '\0' || \
				str[index + 1] != ' ' || str[index + 1] != '	'))
		{
			nbr++;
			index++;
		}
		index++;
	}
	return (nbr);
}

int	unfold_main(t_env *env, t_parser *parser, char *file)
{
	size_t	len;

	len = find_env_variable(parser->cmd);
	if (len)
	{
		printf("%zu\n", len);
		unfold_variable(env, parser->cmd, len);
		return (0);
	}
	len = find_env_variable(file);
	if (len)
		unfold_variable(env, file, len);
	return (0);
}
