/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:42:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/21 17:40:59 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#include "libft/libft.h"

void	padding_char(ssize_t len, char c)
{
	char	*padding;

	padding = malloc(len * sizeof(char));
	if (!padding)
	{
		ft_putendl_fd("Allocation error in padding_char()", 2);
		return ;
	}
	ft_memset(padding, c, len);
	write(1, padding, len);
	free(padding);
}

void	ft_putunbr(unsigned long nbr, unsigned int base, int uppercase, ssize_t len)
{
	char		*numbers;
	char const	*hex;
	int			numdigits;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	numdigits = len;
	numbers = malloc(numdigits * sizeof(char));
	if (!numbers)
	{
		ft_putendl_fd("Allocation error in ft_putunbr()", 2);
		return ;
	}
	while (nbr)
	{
		if (nbr < 0)
			numbers[--numdigits] = hex[-nbr % base];
		else
			numbers[--numdigits] = hex[nbr % base];
		nbr /= base;
	}
	write(1, numbers, len);
	free(numbers);
/*
	if (nbr >= base)
		ft_putunbr(nbr / base, base, uppercase);
	if (uppercase)
		ft_putchar_fd("0123456789ABCDEF"[nbr % base], 1);
	else
		ft_putchar_fd("0123456789abcdef"[nbr % base], 1);
*/
}

void	ft_putnbr(int nbr, ssize_t len)
{
	char	*numbers;
	int		numdigits;

	numdigits = len;
	numbers = malloc(numdigits * sizeof(char));
	if (!numbers)
	{
		ft_putendl_fd("Allocation error in ft_putnbr()", 2);
		return ;
	}
	while (nbr)
	{
		if (nbr < 0)
			numbers[--numdigits] = -(nbr % 10) + '0';
		else
			numbers[--numdigits] = nbr % 10 + '0';
		nbr /= 10;
	}
	write(1, numbers, len);
	free(numbers);
}

int	get_numudigits(unsigned long nbr, int base)
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

int	get_numdigits(int nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
