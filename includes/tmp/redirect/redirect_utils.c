/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:09:35 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/17 12:50:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/redirect.h"
#include "../../includes/parser.h"
#include "../../includes/error.h"

char	*ft_strjoin_red(char *s1, char const *s2, t_parser *node)
{
	char	*tmp;
	char	*str;
	size_t	len;
	size_t	i;

	tmp = s1;
	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		len = ft_strlen(s2) + 1;
	else
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (char_malloc_error(node));
	i = 0;
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i++] = '\n';
	if (tmp)
		free(tmp);
	return (str);
}
