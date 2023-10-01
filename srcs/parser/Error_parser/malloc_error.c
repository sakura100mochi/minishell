/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:02:09 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/10/01 16:17:00 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/parser.h"

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

char	**chardouble_malloc_error(void)
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

void	void_malloc_error(void)
{
	write(STDOUT_FILENO, "malloc_error\n", 13);
	exit(0);
}
