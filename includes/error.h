/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:24:18 by yhirai            #+#    #+#             */
/*   Updated: 2023/11/17 23:06:14 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

/*---Error_malloc---*/
t_parser	*parser_malloc_error(t_parser *node);
char		**onephrase_malloc_error(char **one_phrase, t_parser *node);
char		*char_malloc_error(t_parser *node);
int			int_malloc_error(t_parser *node);
void		exit_malloc_error(void);
/*------------------*/

/*---Error---*/
void		command_not_found(t_env *env, char *str);
int			syntax(t_data *data);
// int			redirect_syntax(t_data *data);
int			no_file(t_data *data, char *file_name);
int			permission(t_data *data, char *file_name);
int			ambiguous(t_data *data, char *file_name);
int			is_directory(t_data *data, char *file_name);
void		pipe_execve_error(t_parser *parser, size_t status);
/*-----------*/

#endif