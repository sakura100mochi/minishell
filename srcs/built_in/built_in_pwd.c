/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 20:34:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	built_in_pwd(void)
{
	char	*wd_path;

	wd_path = NULL;
	ft_printf("pwd:Not yet implemented.\n");
	wd_path = getcwd(wd_path, PATH_MAX);
	ft_printf("%s\n", wd_path);
	free(wd_path);
	return ;
}
