/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 18:02:42 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	print_echo_option(t_parser *parser, size_t flag,
											char *tmp, char *str)
{
	if (!flag)
		ft_printf("%s %s\n", parser->option, str);
	else if (flag && tmp == NULL)
		ft_printf("%s", str);
	else if (flag && tmp)
	{
		ft_printf("%s %s", tmp, str);
		free(tmp);
	}
	return ;
}

static int	check_n_option(t_parser *parser, size_t start)
{
	size_t	index;

	index = start;
	while (parser->option[index] != ' ' && parser->option[index] != '	')
	{
		if (parser->option[index] != 'n')
			return (NO);
		index++;
	}
	return (YES);
}

static int	check_echo_option(t_parser *parser, char *str)
{
	size_t	i;
	size_t	flag;
	char	*tmp;

	i = 0;
	flag = 0;
	tmp = NULL;
	if (parser->option == NULL)
		return (NO);
	if (parser->option[i] == '-' && check_n_option(parser, i + 1))
		flag++;
	while (parser->option[i++] != '\0' && flag)
	{
		if (parser->option[i] == '-' && !check_n_option(parser, i + 1))
		{
			tmp = ft_substr(parser->option, i, ft_strlen(parser->option));
			if (tmp == NULL)
			{
				ft_printf("malloc error\n");
				return (YES);
			}
		}
	}
	print_echo_option(parser, flag, tmp, str);
	return (YES);
}

void	built_in_echo(t_env *env, t_parser *parser, char *str)
{
	if (check_echo_option(parser, str))
	{
		g_status = 0;
		return ;
	}
	if (!parser->option && !*str)
		ft_printf("\n");
	else if (!parser->option && *str)
		ft_printf("%s\n", str);
	g_status = 0;
	(void)env;
	return ;
}
