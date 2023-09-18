/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:11:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 13:59:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/ft_printf.h"

void	ft_process(va_list stat, t_check *check)
{
	if (check -> type == CHAR || check -> type == STRING)
		ft_process_litter(stat, check);
	if (check -> type == POINT)
		ft_process_point(stat, check);
	if (check -> type == DECIMAL || check -> type == INTEJER)
		ft_process_number(stat, check);
	if (check -> type == UNSIGNED)
		ft_process_number(stat, check);
	if (check -> type == HEXALOW || check -> type == HEXAUPP)
		ft_process_hexa(stat, check);
	if (check -> type == PERCENT)
		ft_process_litter(stat, check);
	return ;
}

void	ft_ch_printf(const char *format, va_list stat, int i, t_check *check)
{
	if (format[i] == 'c')
		check -> type = CHAR;
	if (format[i] == 's')
		check -> type = STRING;
	if (format[i] == 'p')
		check -> type = POINT;
	if (format[i] == 'd')
		check -> type = DECIMAL;
	if (format[i] == 'i')
		check -> type = INTEJER;
	if (format[i] == 'u')
		check -> type = UNSIGNED;
	if (format[i] == 'x')
		check -> type = HEXALOW;
	if (format[i] == 'X')
		check -> type = HEXAUPP;
	if (format[i] == '%')
		check -> type = PERCENT;
	ft_process(stat, check);
	return ;
}
