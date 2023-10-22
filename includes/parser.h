/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/21 20:50:25 by hiraiyuina       ###   ########.fr       */
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
t_parser		*parser_main(char **str, char *prompt);
t_parser		*split_pipe(char **str, char *prompt, t_parser	*node);
char			*ft_strjoin_minis(char *s1, char const *s2, t_parser *node);
char			*ft_strjoin_all(char *all, t_parser *node);
t_parser		*ft_parsernew(char *all, char *cmd, char *option, t_file *redirect);
void			ft_parseradd_back(t_parser **node, t_parser *new);
t_parser		*ft_parserlast(t_parser *node);
size_t			ft_parsersize(t_parser *node);
t_file			*ft_filenew(char **one_phrase, t_parser *node);
int				quote_check(char *str);
t_redirect_type	file_type(char **one_phrase);
void			ft_fileadd_back(t_file **file, t_file *new);
t_file			*ft_filelast(t_file *file);
char			*ft_command(char **one_phrase, t_parser *node);
char			*ft_command_add(char *cmd, char *one_phrase, t_parser *node);
char			*ft_option(char **one_phrase, t_parser *node);
t_file			*ft_redirect(char **one_phrase, t_parser *node);
char			*ft_all(char *prompt, size_t *k);
/*------------*/

#endif