/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:28:12 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/22 18:18:10 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin_minis(char *s1, char const *s2)
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
		return (char_malloc_error());
	i = 0;
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	if (s1 != NULL)
		str[i++] = ' ';
	while (*s2 != '\0')
		str[i++] = *s2++;
	return (str);
}