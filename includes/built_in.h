/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/21 09:32:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*---include---*/
# include "minishell.h"
/*-------------*/

int		judge_built_in(t_data *data, t_parser *parser, char *file);
t_env	*serch_env_variable(t_env *head, char *variable);
char	*wrap_with_quotes(char *str);
char	*create_file_path(char *file);
char	*variable_format(t_env *env, char *str);
t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char *file);
void	built_in_echo(t_env *env, t_parser *parser, char *str);
void	built_in_env(t_env *env_variable, t_parser *parser, char *file);
void	built_in_exit(t_data *data, char *file);
void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str);
void	export_no_command(t_exp *exp_variable);
t_env	*input_env_variable(char *str, t_env *env_variable);
t_exp	*input_exp_variable(char *str, t_env *env_variable, \
								t_exp *exp_variable, int flag);
void	built_in_pwd(t_env *env, t_parser *parser);
void	built_in_unset(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char *str);

#endif