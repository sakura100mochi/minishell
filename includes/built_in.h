/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/23 19:34:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---Structure_Declaration---*/
int		judge_built_in(t_init *state, t_parser *parser, char *file);
t_env	*serch_env_variable(t_env *head, char *variable);
t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char *file);
void	built_in_echo(t_init *state, t_parser *parser);
void	built_in_env(t_init *state, t_env *env_variable);
void	built_in_exit(t_init *state);
void	built_in_export(t_exe *exe, t_env *env_variable, t_exp *exp_variable);
void	built_in_pwd(void);
void	built_in_unset(t_exe *exe, t_env *env_variable, t_exp *exp_variable);
/*---------------------------*/

#endif