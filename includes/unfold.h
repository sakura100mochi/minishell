/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfold.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:14:50 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 20:06:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNFOLD_H
# define UNFOLD_H

/*---unfold---*/
# include "minishell.h"
/*------------*/

/*---unfold---*/
int	unfold_main(t_env *env, t_parser *parser, char *file);
/*------------*/

#endif