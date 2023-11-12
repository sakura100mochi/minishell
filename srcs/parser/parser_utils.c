/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:28:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/12 16:03:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

char	*ft_strjoin_minis(char *s1, char const *s2, t_parser *node)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (char_malloc_error(node));
	i = 0;
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	if (s1 != NULL)
		str[i++] = ' ';
	while (*s2 != '\0')
		str[i++] = *s2++;
	return (str);
}

static size_t	ft_strlen_all(char *all)
{
	size_t	i;

	i = 0;
	while (all[i] != '\0' && all[i] != '|')
		i++;
	return (i);
}

char	*ft_strjoin_all(char *all, t_parser *node)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (all == NULL)
		return (NULL);
	len = ft_strlen_all(all);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (char_malloc_error(node));
	i = 0;
	while (*all != '\0' && *all != '|')
		str[i++] = *all++;
	return (str);
}
