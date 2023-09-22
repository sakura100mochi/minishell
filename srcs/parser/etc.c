/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_add_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:26:19 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/20 13:51:31 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_command(char *str)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (YES);
	if (ft_strncmp(str, "cd", 3) == 0)
		return (YES);
	if (ft_strncmp(str, "pwd", 4) == 0)
		return (YES);
	if (ft_strncmp(str, "export", 7) == 0)
		return (YES);
	if (ft_strncmp(str, "unset", 6) == 0)
		return (YES);
	if (ft_strncmp(str, "env", 4) == 0)
		return (YES);
	if (ft_strncmp(str, "exit", 5) == 0)
		return (YES);
	if (ft_strncmp(str, "cat", 4) == 0)
		return (YES);
	return (NO);
}
