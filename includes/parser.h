/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/19 19:09:45 by yhirai           ###   ########.fr       */
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
t_parser	*parsing(t_parser *parse, char **phrase);
t_parser	*command(t_parser *parse, char **phrase);
int			check_command(char *str);
void		ft_bzero_double(char **str);
/*------------*/

#endif