/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:42:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/15 12:42:26 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/libft.h"

void	padding_char(unsigned int len, char c)
{
	while (len-- > 0)
		write(1, &c, 1);
}

void	ft_puthex(unsigned long nbr, int uppercase)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, uppercase);
	if (uppercase)
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
}

void	ft_putnbr(int nbr, int *index, int end)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		if (nbr <= -10)
			ft_putnbr(-(nbr / 10), index, end);
		if (*index < end)
			ft_putchar_fd(-(nbr % 10) + '0', 1);
	}
	else
	{
		if (nbr >= 10)
			ft_putnbr(nbr / 10, index, end);
		if (*index < end)
			ft_putchar_fd(nbr % 10 + '0', 1);
	}
	(*index)++;
}

int	get_numdigits(unsigned long nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
