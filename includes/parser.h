/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/20 13:51:51 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---Structure_Declaration---*/

typedef enum e_redirect_type
{
	UNKNOEN,
	QUOTE_HEREDOC,
	HEREDOC,
	INPUT,
	OUTPUT,
	APPEND
}			t_redirect_type;

typedef struct s_file
{
	char			*file_name;
	t_redirect_type	type;
	struct s_file	*next;
}			t_file;
typedef struct s_parser
{
	char			*cmd;
	char			*option;
	char			*str;
	t_file			*redirect;
	char			*result;
	struct s_parser	*next;
	struct s_parser	*prev;
}			t_parser;
/*---------------------------*/

/*---lexer---*/
char		**lexer_main(char *str);
char		*single_quotation(char **str);
char		*double_quotation(char **str);
char		*split_word(char **str);
/*-----------*/

/*---parser---*/
t_parser	*parser_main(char **str);
t_parser	*split_pipe(char **str, char **one_phrase);
void		ft_bzero_double(char **str);
int			check_command(char *str);
t_parser	*ft_parsernew(char *cmd, char *option, char *str, t_file *redirect);
void		ft_parseradd_back(t_parser **node, t_parser *new);
t_parser	*ft_parserlast(t_parser *node);
char		*ft_command(char **one_phrase);
char		*ft_option(char **one_phrase);
char		*ft_str(char **one_phrase);
t_file		*ft_redirect(char **one_phrase);
/*------------*/

#endif