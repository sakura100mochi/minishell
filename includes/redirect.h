/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:11:32 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/22 14:42:12 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

int		redirect_main(t_data *data, t_parser *node);
int		quote_heredoc(t_data *data, t_file *file);
int		heredoc(t_data *data, t_file *file, char *name);
int		input(t_file *file);
int		append(t_file *file);
int		output(t_file *file);
char	*ft_strjoin_red(char *s1, char const *s2, t_parser *node);

#endif