/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/17 19:55:28 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_quotation(char **str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = *str;
	tmp++;
	while (tmp[i] != '\"' && tmp[i] != '\'' && tmp[i] != '\0')
		i++;
	i += 2;
	*str += i;
	return (1);
}

static size_t	count_word(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (str == NULL)
		return (0);
	count = 1;
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '\"')
			count += count_quotation(&str);
		else
		{
			if (*str == ' ' || *str == '|' || *str == '<' || *str == '>')
				count++;
			*str++;
		}
	}
	*str--;
	if (*str != ' ' && *str != '|' && *str != '<' && *str != '>')
		count++;
	return (count);
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
		if (*str == '\'')
			result[i] = single_quotation(&str);
		else if (*str == '\"')
			result[i] = double_quotation(&str);
		else
			result[i] = split_word(&str);
		if (result[i] == NULL)
			return (ft_free(result));
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	**result;
// 	char	str[] = "echo 'orld' \"hello\" cat < file | ";
// 	int		i;

// 	result = lexer_main(str);
// 	i = 0;
// 	while (result[i] != '\0')
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	ft_free(result);
// 	return (0);
// }
