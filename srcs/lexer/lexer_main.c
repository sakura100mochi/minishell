/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/11 15:52:44 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

static size_t	count_quotation(char *str, size_t *i)
{
	size_t	j;
	size_t	single;
	size_t	twofold;

	j = 1;
	single = 0;
	twofold = 0;
	if (str[0] == '\'')
		single++;
	else if (str[0] == '"')
		twofold++;
	while (single != 0 && str[j] != '\'' && str[j] != '\0')
		j++;
	while (twofold != 0 && str[j] != '"' && str[j] != '\0')
		j++;
	if (str[j] != '\0')
		j++;
	*i += j;
	return (1);
}

static int	check_char(char c, char d)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	if ((c != ' ' && c != '	' && c != '|' && c != '<' && c != '>')
		&& (d == ' ' || d == '	' || d == '|' || d == '<' || d == '>'
			|| d == '\'' || d == '\"' || d == '\0'))
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
		if (str[i] == '\'' || str[i] == '\"')
			count += count_quotation(&str[i], &i);
		else
		{
			if (check_char(str[i], str[i + 1]) == YES)
				count++;
			i++;
		}
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

char	**lexer_main(t_data *data, char *str)
{
	size_t	i;
	char	**result;

	i = 0;
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
// 	char	str[] = " ";
// 	int		i;

// 	result = lexer_main(str);
// 	if (result == NULL)
// 		return (0);
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	ft_free(result);
// 	return (0);
// }
