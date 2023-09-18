/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 18:48:58 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---Structure_Declaration---*/
typedef struct s_env
{
	int					head;
	char				*variable;
	struct s_env		*prev;
	struct s_env		*next;
}						t_env;
/*---------------------------*/

#endif