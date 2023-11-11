/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/11 13:12:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

static size_t	count_quotation(char *str)
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
	return (j);
}

static int	check_char(char c, char d)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	if ((c == ' ' || c == '	') && d == '-')
		return (YES);
	if ((c != '|' && c != '<' && c != '>')
		&& (d == '|' || d == '<' || d == '>' || d == '\0'))
		return (YES);
	return (NO);
}

static size_t	count_word(char *str)
{
	size_t	i;
	size_t	count;
	size_t	option;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	option = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i += count_quotation(&str[i]);
		else
		{
			if (check_char(str[i], str[i + 1]) == YES)
				count++;
			if ((str[i] == ' ' || str[i] == '	') && str[i + 1] == '-')
				option++;
			i++;
		}
	}
	if (option)
		option--;
	return (count + option + 1);
}

static char	**ft_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**lexer_main(char *str)
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
			return (ft_free(result));
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
