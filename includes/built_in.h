/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 18:56:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---Structure_Declaration---*/
typedef struct s_env
{
	int					head;
	char				*variable;
	struct s_env		*prev;
	struct s_env		*next;
}						t_env;
/*---------------------------*/

int		judge_built_in(t_init *state, char **exe_buil_command);
void	built_in_cd(void);
void	built_in_echo(t_init *state);
void	built_in_env(t_init *state, t_env *env_variable);
void	built_in_exit(t_init *state);
void	built_in_pwd(void);
void	built_in_unset(void);

#endif