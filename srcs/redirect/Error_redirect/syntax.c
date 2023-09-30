/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:26:38 by yhirai            #+#    #+#             */
/*   Updated: 2023/09/30 15:00:11 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

void	syntax(char *str)
{
	if (str == NULL)
		ft_printf("minishell: syntax error near unexpected token `newline'\n");
	else
		ft_printf("minishell: syntax error near unexpected token `%s'\n", str);
}
