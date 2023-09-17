/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:18:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/17 16:23:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	judge_built_in(t_init *state, char **exe_built_command)
{
	size_t	len;

	len = ft_strlen(exe_built_command[0]);
	// printf("len%zu, command:%s\n", len, exe_built_command[0]);
	if (len == 2 && !ft_strncmp(exe_built_command[0], "cd", len))
		built_in_cd();
	else if (len == 4 && !ft_strncmp(exe_built_command[0], "echo", len))
		built_in_echo();
	else if (len == 3 && !ft_strncmp(exe_built_command[0], "env", len))
		built_in_env(state);
	else if (len == 4 && !ft_strncmp(exe_built_command[0], "exit", len))
		built_in_exit(state);
	else if (len == 3 && !ft_strncmp(exe_built_command[0], "pwd", len))
		built_in_pwd();
	else if (len == 5 && !ft_strncmp(exe_built_command[0], "unset", len))
		built_in_unset();
	else
		return (1);
	double_array_free(exe_built_command);
	return (0);
}
