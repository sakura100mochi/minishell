/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/28 16:45:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*---include---*/
# include "minishell.h"
/*-------------*/

int		judge_built_in(t_data *data, t_parser *parser, \
									char *file, char **array);
t_env	*serch_env_variable(t_env *head, char *variable);
char	*wrap_with_quotes(char *str);
char	*create_file_path(char *file);
size_t	count_file_nbrs(char *file);
char	**file_to_array(t_env *env, char *str);
char	*variable_format(t_env *env, char *str);
t_env	*built_in_cd(t_env *env_variable, t_parser *parser, char **array);
int		change_directory(t_env *head, t_parser *parser, char *file);
void	built_in_echo(t_env *env, t_parser *parser, char *str);
void	built_in_env(t_env *env_variable, t_parser *parser, char *file);
void	built_in_exit(t_env *env, t_parser *parser, char **array);
void	built_in_export(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char **array);
void	export_no_command(t_env *env_variable, t_exp *exp_variable);
void	do_export(t_env *env_variable, t_exp *exp_variable, \
										char *variable, char *str);
t_env	*input_env_variable(char *str, t_env *env_variable);
t_exp	*input_exp_variable(char *str, t_exp *exp_variable, int flag);
t_env	*redeclare_env(t_env *env, char *variable, char *tmp);
t_exp	*redeclare_exp(t_exp *exp, char *variable, char *tmp);
int		check_envvariable_exist(t_env *env, char *str);
int		check_expvariable_exist(t_exp *exp, char *str);
void	built_in_pwd(t_env *env, t_parser *parser);
void	built_in_unset(t_parser *parser, t_env *env_variable, \
									t_exp *exp_variable, char **array);

#endif