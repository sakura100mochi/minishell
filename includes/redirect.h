/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:11:32 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 17:57:04 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

void	redirect_main(t_data *data, t_parser *node);
void	check_fd(t_data *data, t_parser *node, t_file *file, char *str);
void	cmd_redirect(t_data *data, t_parser *node, int fd, char *str);
char	*quote_heredoc(t_parser *node, t_file *file);
char	*heredoc(t_parser *node, char *file_name);
void	input(t_parser *node, t_file *file);
void	append(t_parser *node, t_file *file);
void	output(t_parser *node, t_file *file);
char	*ft_strjoin_red(char *s1, char const *s2);

/*---Error---*/
void	syntax(char *str);
void	no_file(char *file_name);
void	permission(char *file_name);
/*-----------*/

#endif