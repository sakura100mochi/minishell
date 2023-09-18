/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 11:50:30 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe_ext_command(t_init *state, t_exe *exe_ext, char **command)
{
	char		*exe;
	extern char	**environ;

	(void)state;
	exe = ft_strjoin(BINARY, command[0]);
	exe_ext->exe_flag = execve(exe, command, environ);
	perror("execve");
	// exit(EXIT_SUCCESS);
}

void	external_command(t_init *state, t_exe *exe_ext)
{
	int		status;

	status = 0;
	exe_ext->pid = fork();
	// printf("process:%d, %s\n", exe_ext->pid, state->env[1]);
	if (exe_ext->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_ext->pid == 0)
		exe_ext_command(state, exe_ext, exe_ext->command);
	else
		waitpid(exe_ext->pid, &status, 0);
	double_array_free(exe_ext->command);
	return ;
}
