/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:02:09 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/22 18:16:53 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_parser	*parser_malloc_error(void)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	exit(0);
	return (NULL);
}

char	*char_malloc_error(void)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	exit(0);
	return (NULL);
}

t_file	*file_malloc_error(void)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	exit(0);
	return (NULL);
}
