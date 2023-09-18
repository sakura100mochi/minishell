/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 11:51:01 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	built_in_env(t_init *state)
{
	size_t		i;
	extern char	**environ;

	(void)state;
	i = 0;
	printf("env:Not yet implemented.\n");
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return ;
}
