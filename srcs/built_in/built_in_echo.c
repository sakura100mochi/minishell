/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 02:15:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_echo(t_init *state, t_parser *parser)
{
	(void)state;
	ft_printf("echo:Not yet implemented.\n");
	if (!parser->option)
	if (parser->option && !ft_strncmp((parser->option), "-n", 2))
		ft_printf("%s", parser->str);
	else
		ft_printf("%s\n", parser->str);
	return ;
}
