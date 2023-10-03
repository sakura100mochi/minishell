/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:14:50 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/03 15:01:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNFOLD_H
# define UNFOLD_H

/*---unfold---*/
# include "minishell.h"
/*------------*/

/*---unfold---*/
int		unfold_main(t_env *env, t_parser *parser, char *file);
int		remove_quote_in_command(t_parser *parser, char *str);
char	*unfold_quote_variable(char *str, size_t start, size_t enc);
/*------------*/

#endif