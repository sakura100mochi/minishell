/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/01 13:06:55 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---lexer---*/
char			**lexer_main(char *str);
char			*split_word(char **str);
/*-----------*/

/*---parser---*/
t_parser		*parser_main(char **str);
t_parser		*split_pipe(char **str);
char			*ft_strjoin_minis(char *s1, char const *s2);
t_parser		*ft_parsernew(char *cmd, char *option, t_file *redirect);
void			ft_parseradd_back(t_parser **node, t_parser *new);
t_parser		*ft_parserlast(t_parser *node);
t_file			*ft_filenew(char **one_phrase);
t_redirect_type	file_type(char **one_phrase);
void			ft_fileadd_back(t_file **file, t_file *new);
t_file			*ft_filelast(t_file *file);
char			*ft_command(char **one_phrase);
char			*ft_command_add(char *cmd, char *one_phrase);
char			*ft_option(char **one_phrase);
t_file			*ft_redirect(char **one_phrase);
/*------------*/

/*---Error_parser---*/
t_parser		*parser_malloc_error(void);
char			*char_malloc_error(void);
t_file			*file_malloc_error(void);
/*------------------*/

#endif