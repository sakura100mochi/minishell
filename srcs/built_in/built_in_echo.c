/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/24 05:41:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_echo(t_init *state, t_parser *parser, char *str)
{
	size_t	len;

	(void)state;
	ft_printf("echo:Not yet implemented.\n");
	len = ft_strlen(parser->option);
	if (!*(parser)->option && !*str)
		ft_printf("\n");
	else if (!*(parser)->option && *str)
		ft_printf("%s\n", str);
	else if (!ft_strncmp((parser->option), "-n", len) && !*str)
		return ;
	else if (!ft_strncmp((parser->option), "-n", len) && *str)
		ft_printf("%s", str);
	else if (ft_strncmp((parser->option), "-n", len) && !*str)
		ft_printf("%s\n", parser->option);
	else if (ft_strncmp((parser->option), "-n", len) && *str)
		ft_printf("%s %s\n", parser->option, str);
	return ;
}
