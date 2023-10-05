/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:14:50 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/05 10:46:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNFOLD_H
# define UNFOLD_H

/*---unfold---*/
# include "minishell.h"
/*------------*/

/*---unfold---*/
char	*unfold_main(t_env *env, t_parser *parser, char *file);
char	*check_quote_in_str(char *str, t_env *env);
int		check_env_variable(char *str, size_t start, size_t end);
size_t	cnt_env_variable(char *str);
char	*unfold_str(char *str, t_env *env, size_t *start);
char	*unfold_quote_variable(char *str, t_env *env, size_t start, size_t end);
int		unfold_split_words(char **strage, t_env *env);
char	*str_connection(char *result, char *str, size_t start, size_t end);
char	**split_env_variable(char *tmp, size_t len);
char	*strjoin_mini(const char *s1, const char *s2);
/*------------*/

#endif