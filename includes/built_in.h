/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/25 16:43:02 by csakamot         ###   ########.fr       */
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
char	*wrap_with_quotes(char *str);
t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char *file);
void	built_in_echo(t_parser *parser, char *str);
void	built_in_env(t_env *env_variable, t_parser *parser, char *file);
void	built_in_exit(t_init *state, char *file);
void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str);
void	built_in_pwd(void);
void	built_in_unset(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str);
/*---------------------------*/

#endif