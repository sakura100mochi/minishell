/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 13:22:46 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_quotation(char *str, size_t *i)
{
	size_t	j;

	j = 1;
	while (str[j] != '\"' && str[j] != '\'' && str[j] != '\0')
		j++;
	j++;
	*i += j;
	return (1);
}

static size_t	count_word(char *str)
{
	size_t	i;
	size_t	count;

	if (str == NULL)
		return (0);
	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			count += count_quotation(&str[i], &i);
		else
		{
			if (str[i] == ' ' || str[i] == '|'
				|| str[i] == '<' || str[i] == '>')
				count++;
			i++;
		}
	}
	i--;
	if (str[i] != ' ' && str[i] != '|' && str[i] != '<' && str[i] != '>')
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
