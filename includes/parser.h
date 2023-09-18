/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/18 18:57:28 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---Structure_Declaration---*/
typedef struct s_parser
{
	char			*command;
	char			*option;
	char			*file_name;
	char			*redirection;
	char			*result;
	struct s_parser	*next;
	struct s_parser	*pre;
}			t_parser;
/*---------------------------*/

/*---parser---*/
t_parser	*parser_main(char **str);
t_parser	*parsing(t_parser *parse, char **phrase);
int			check_command(char *str);
void		ft_bzero_double(char **str);
/*------------*/

#endif