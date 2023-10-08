/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_cnt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 14:00:21 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/ft_printf.h"

static void	ft_number(unsigned long long nb, int length, char *moto)
{
	if (nb >= (unsigned long long)(length))
	{
		ft_number(nb / length, length, moto);
		ft_number(nb % length, length, moto);
	}
	else
		ft_putchar_fd(moto[nb], 1);
}

int	ft_putnbr_base_fdcnt(long long nbr, int digit, char *base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		digit++;
	while (base[len] != '\0')
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_number((unsigned long long)nbr, len, base);
	}
	else if (nbr >= 0)
		ft_number(nbr, len, base);
	while (nbr)
	{
		digit++;
		nbr /= len;
	}
	return (digit);
}

int	ft_putnbr_base_fdcnt2(unsigned long long nbr, int digit, char *base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		digit++;
	while (base[len] != '\0')
		len++;
	ft_number(nbr, len, base);
	while (nbr)
	{
		digit++;
		nbr /= len;
	}
	return (digit);
}
