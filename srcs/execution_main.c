/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/23 19:29:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

static char	*format_command(t_parser *parser)
{
	size_t	cmd_len;
	size_t	file_len;
	char	*tmp;
	char	*file;

	cmd_len = 0;
	while (parser->cmd[cmd_len] != ' ' && parser->cmd[cmd_len] != '\0')
		cmd_len++;
	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
	tmp = ft_substr(parser->cmd, 0, cmd_len);
	file = ft_substr(parser->cmd, cmd_len + 1, file_len);
	free(parser->cmd);
	parser->cmd = tmp;
	return (file);
}

static int	check_cmd_access(t_parser *parser, char **path)
{
	size_t	index;
	char	*tmp;
	char	*full_path;

	index = 0;
	while (!path[index])
	{
		tmp = ft_strjoin(path[index], "/");
		full_path = ft_strjoin(tmp, parser->cmd);
		if (!access(full_path, X_OK))
		{
			free(tmp);
			free(full_path);
			return (0);
		}
		free(tmp);
		free(full_path);
		index++;
	}
	double_array_free(path);
	return (1);
}

static int	check_cmd_path(t_env *env_variable, t_parser *parser)
{
	size_t	len;
	size_t	index;
	char	**path;

	index = 0;
	env_variable = env_variable->next;
	while (!env_variable->head)
	{
		len = ft_strlen(env_variable->variable);
		if (len < 5)
			return (1);
		else if (!ft_strncmp(env_variable->variable, "PATH=", 5))
		{
			path = ft_split(env_variable->variable, ':');
			break ;
		}
		env_variable = env_variable->next;
	}
	if (!check_cmd_access(parser, path))
		return(0);
	return (1);
}

void	execution_main(t_init *state)
{
	char	*file;

	file = format_command(state->parser);
	if (judge_built_in(state, state->parser, file))
		external_command(state, state->parser, file);
}
