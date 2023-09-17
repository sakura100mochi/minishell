/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:31:48 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 13:59:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/ft_printf.h"

int	ft_sp_output(const char *format, va_list stat, int i)
{
	int		len;
	t_check	*check;

	check = (t_check *)ft_calloc(1, sizeof(t_check));
	if (check == NULL)
		return (0);
	ft_ch_printf(format, stat, i, check);
	len = check -> length;
	free(check);
	return (len);
}

int	ft_output(const char *format, va_list stat)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd((char)format[i], 1);
			i++;
			len++;
			continue ;
		}
		len += ft_sp_output(format, stat, ++i);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	stat;
	int		count;

	count = 0;
	va_start(stat, format);
	count = ft_output(format, stat);
	va_end(stat);
	return (count);
}
