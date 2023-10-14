/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:24:18 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/14 16:37:16 by yhirai           ###   ########.fr       */
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
/*------------------*/

/*---Error---*/
void		command_not_found(char *str);
int			syntax(void);
void		syntax_void(void);
int			no_file(char *file_name);
int			permission(char *file_name);
/*-----------*/

#endif