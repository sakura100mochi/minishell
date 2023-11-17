/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 20:33:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/error.h"

static void	print_echo_option(char *tmp, char *str, size_t index)
{
	if (!tmp && str)
		ft_printf("%s", str);
	else if (!index && *str)
		ft_printf("%s %s\n", tmp, str);
	else if (!index && !*str)
		ft_printf("%s\n", tmp);
	else if (index && *str)
		ft_printf("%s %s", tmp, str);
	else if (index && !*str)
		ft_printf("%s", tmp);
	return ;
}

static int	check_echo_option(char *option, size_t index)
{
	while (option[index] != '\0' && option[index] == 'n')
		index++;
	if (option[index] == ' ' || option[index] == '	' \
									|| option[index] == '\0')
		return (YES);
	return (NO);
}

static void	do_echo_option(t_parser *parser, char *str)
{
	size_t	index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	while (parser->option[index] != '\0')
	{
		if (index > 0 && parser->option[index - 1] == '-' && \
			!check_echo_option(parser->option, index))
		{
			tmp = ft_substr(parser->option, index - 1, \
					ft_strlen(parser->option) - index + 1);
			if (!tmp)
				exit_malloc_error();
			break ;
		}
		index++;
	}
	if (ft_strlen(parser->option) == 1)
		tmp = ft_substr(parser->option, index - 1, \
			ft_strlen(parser->option) - index + 1);
	print_echo_option(tmp, str, index - 1);
	if (tmp)
		free(tmp);
	return ;
}

void	built_in_echo(t_env *env, t_parser *parser, char *str)
{
	if (parser->option)
		do_echo_option(parser, str);
	else if (!parser->option && !*str)
		ft_printf("\n");
	else if (!parser->option && *str)
		ft_printf("%s\n", str);
	env->status = 0;
	return ;
}
