/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 12:14:47 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_init	state;

	init_minishell(&state);
	signal_minishell(state.signal->action);
	standby_state(&state);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	char	*str = "echo";
// 	char	**array;
// 	// extern char	**environ;

// 	array = ft_split(str, ' ');
// 	for (int i = 0; array[i]; i++)
// 		printf("%s\n", array[i]);
// 	double_array_free(array);
// 	// for (int i = 0; environ[i]; i++)
// 	// 	printf("%s\n", environ[i]);
// 	// execve("/bin/ls", argv, NULL);
// 	// printf("errno:%d\n", errno);
// 	// perror("fork");
// 	return (0);
// }

__attribute__((destructor))
static void destructor() {
    system("leaks -q minishell");
}
