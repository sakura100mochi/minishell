/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 10:16:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_echo(t_init *state, t_parser *parser)
{
	size_t	len;

	(void)state;
	ft_printf("echo:Not yet implemented.\n");
	len = ft_strlen(parser->option);
	if (!*(parser)->option && !parser->str)
		ft_printf("\n");
	else if (!*(parser)->option && *(parser)->str)
		ft_printf("%s\n", parser->str);
	else if (*(parser)->option && !ft_strncmp((parser->option), "-n", len) \
														&& !parser->str)
		return ;
	else if (*(parser)->option && !ft_strncmp((parser->option), "-n", len) \
														&& *(parser)->str)
		ft_printf("%s", parser->str);
	else if (*(parser)->option && ft_strncmp((parser->option), "-n", len) \
														&& !parser->str)
		ft_printf("%s\n", parser->option);
	else if (*(parser)->option && ft_strncmp((parser->option), "-n", len) \
														&& !*(parser)->str)
		ft_printf("%s\n", parser->option);
	else if (*(parser)->option && ft_strncmp((parser->option), "-n", len) \
														&& *(parser)->str)
		ft_printf("%s %s\n", parser->option, parser->str);
	return ;
}
