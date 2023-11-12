/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/12 16:46:50 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

static int	check_char(char c, char d)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	if ((c != ' ' && c != '	' && c != '|' && c != '<' && c != '>')
		&& (d == ' ' || d == '	' || d == '|' || d == '<' || d == '>'
			|| d == '\0'))
		return (YES);
	return (NO);
}

static size_t	count_word(char *str)
{
	size_t	i;
	size_t	count;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_char(str[i], str[i + 1]) == YES)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(t_data *data, char **result)
{
	size_t	i;

	i = 0;
	syntax(data);
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**lexer_main(t_data *data)
{
	size_t	i;
	char	**result;
	char	*str;

	i = 0;
	str = data->prompt;
	result = (char **)ft_calloc(sizeof(char *), count_word(str) + 1);
	if (result == NULL)
		return (NULL);
	while (*str != '\0')
	{
		result[i] = split_word(&str);
		if (result[i] == NULL)
			return (ft_free(data, result));
		i++;
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**result;
// 	t_data *data;
// 	char	str[] = "cat <<\"cat | ls\"";
// 	int		i;

// 	data = malloc(sizeof(t_data));
// 	data->prompt = str;
// 	result = lexer_main(data);
// 	if (result == NULL)
// 		return (0);
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	ft_free(NULL, result);
// 	return (0);
// }
