/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/22 15:35:33 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---Structure_Declaration---*/

// HEREDOC <<
// INPUT <
// APPEND >>
// OUTPUT >
// UNKNOWN
// QUOTE_HEREDOC << '', << ""
typedef enum e_redirect_type
{
	HEREDOC,
	INPUT,
	APPEND,
	OUTPUT,
	UNKNOWN,
	QUOTE_HEREDOC
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
char		*ft_strjoin_minis(char *s1, char const *s2);
int			check_command(char *str);
t_parser	*ft_parsernew(char *cmd, char *option, t_file *redirect);
void		ft_parseradd_back(t_parser **node, t_parser *new);
t_parser	*ft_parserlast(t_parser *node);
t_file		*ft_filenew(char **one_phrase);
void		ft_fileadd_back(t_file **file, t_file *new);
t_file		*ft_filelast(t_file *file);
char		*ft_command(char **one_phrase);
char		*ft_option(char **one_phrase);
t_file		*ft_redirect(char **one_phrase);
/*------------*/

#endif