/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:19:40 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/17 15:47:36 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"
#include "ft_printfints.h"

static void	ft_printfint_symbol(int nbr, t_flags flags)
{
	if (nbr >= 0)
	{
		if (flags & SIGN_SYMBOL)
			write(1, "+", 1);
		else if (flags & SPACE_SIGN)
			write(1, " ", 1);
	}
	else
		write(1, "-", 1);
}

ssize_t	ft_printfintn(t_info info, int symbol, t_flags flags)
{
	int		index;
	ssize_t	len;

	index = 0;
	if (info.width > info.len + symbol)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + symbol), '0');
		ft_putnbr(info.nbr, &index, -1);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.len + symbol), ' ');
		len = info.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		ft_putnbr(info.nbr, &index, -1);
		len = info.len + symbol;
	}
	return (len);
}

static ssize_t	ft_printfintpp(t_info info, int symbol, t_flags flags)
{
	int		index;
	ssize_t	len;

	index = 0;
	if (info.width > info.precision + symbol)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.precision + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		padding_char(info.precision - info.len, '0');
		ft_putnbr(info.nbr, &index, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.precision + symbol), ' ');
		len = info.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		padding_char(info.precision - info.len, '0');
		ft_putnbr(info.nbr, &index, info.len);
		len = info.precision + symbol;
	}
	return (len);
}

static ssize_t	ft_printfintnn(t_info info, int symbol, t_flags flags, int *id)
{
	ssize_t	len;

	if (info.width >= info.len + symbol)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		if (info.precision != 0 || info.nbr != 0)
			ft_putnbr(info.nbr, id, -1);
		else
			write(1, " ", 1);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.len + symbol), ' ');
		len = info.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		if (info.precision != 0 || info.nbr != 0)
			ft_putnbr(info.nbr, id, info.len);
		len = info.len + symbol;
	}
	return (len);
}

ssize_t	ft_printfintp(t_info info, int symbol, t_flags flags)
{
	ssize_t	len;
	int		index;

	index = 0;
	if (info.precision > info.len)
		len = ft_printfintpp(info, symbol, flags);
	else
		len = ft_printfintnn(info, symbol, flags, &index);
	return (len);
}
