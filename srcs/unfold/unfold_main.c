/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:53 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/05 10:55:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unfold.h"

// static int	input_variable(t_env *env, char *str, char **strage)
// {
// 	size_t	index;
// 	size_t	cnt;
// 	size_t	start;

// 	(void)env;
// 	index = 0;
// 	cnt = 0;
// 	start = 0;
// 	while (str[index] != '\0')
// 	{
// 		if (str[index] == '$' && !start && (str[index] != ' ' || \
// 												str[index] != '	'))
// 			start = index + 1;
// 		else if (start && (str[index + 1] == ' ' || str[index + 1] == '	' || \
// 							str[index + 1] == '\0' || str[index + 1] == '$'))
// 		{
// 			strage[cnt++] = ft_substr(str, start, index - start + 1);
// 			start = 0;
// 		}
// 		index++;
// 	}
// 	strage[cnt] = NULL;
// 	return (0);
// }

// // static char	*create_unfoled_str(char *str, char **strage)
// // {
// // 	return (str);
// // }

// static char	*unfold_variable(t_env *env, char *str, size_t len)
// {
// 	// char	*result;
// 	char	**strage;

// 	strage = (char **)ft_calloc(sizeof(char *), len + 1);
// 	input_variable(env, str, strage);
// 	for (int i = 0; strage[i] != NULL; i++)
// 		printf("%s\n", strage[i]);
// 	// result = create_unfoled_str(str, strage);
// 	double_array_free(strage);
// 	return (NULL);
// }

char	*str_connection(char *result, char *str, size_t start, size_t end)
{
	char	*tmp_f;
	char	*tmp_b;

	tmp_f = ft_substr(str, 0, start);
	tmp_b = ft_substr(str, end, ft_strlen(str));
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
		if (str[index] == '$' && (str[index + 1] != '\0' || \
		str[index + 1] != ' ' || str[index + 1] != '	' || \
		str[index + 1] != '\''))
		{
			nbr++;
			index++;
		}
		index++;
	}
	return (nbr * 2 + 1);
}

char	*unfold_main(t_env *env, t_parser *parser, char *file)
{
	parser->cmd = check_quote_in_str(parser->cmd, env);
	if (file)
	{
		file = check_quote_in_str(file, env);
	}
	return (file);
}
