/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:11:32 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/24 19:53:48 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

void	redirect_main(t_parser *node);
void	quote_heredoc(t_parser *node, t_file *file);
void	heredoc(t_parser *node, t_file *file);
void	input(t_parser *node, t_file *file);
void	append(t_parser *node, t_file *file);
void	output(t_parser *node, t_file *file);

/*---Error---*/
void	syntax(void);
/*-----------*/

#endif