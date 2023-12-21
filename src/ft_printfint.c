/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:19:40 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/21 15:57:40 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

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

static ssize_t	ft_printfintpp(t_info info, int symbol, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.size.precision + symbol)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - (info.size.precision + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		padding_char(info.size.precision - info.len, '0');
		ft_putnbr(info.nbr, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - (info.size.precision + symbol), ' ');
		len = info.size.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		padding_char(info.size.precision - info.len, '0');
		ft_putnbr(info.nbr, info.len);
		len = info.size.precision + symbol;
	}
	return (len);
}

static ssize_t	ft_printfintnp(t_info info, int symbol, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.len + symbol)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - (info.len + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		if (info.len > 0)
			ft_putnbr(info.nbr, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - (info.len + symbol), ' ');
		len = info.size.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		if (info.len > 0)
			ft_putnbr(info.nbr, info.len);
		len = info.len + symbol;
	}
	return (len);
}

ssize_t	ft_printfintn(t_info info, int symbol, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.len + symbol)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - (info.len + symbol), ' ');
		ft_printfint_symbol(info.nbr, flags);
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - (info.len + symbol), '0');
		ft_putnbr(info.nbr, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - (info.len + symbol), ' ');
		len = info.size.width;
	}
	else
	{
		ft_printfint_symbol(info.nbr, flags);
		ft_putnbr(info.nbr, info.len);
		len = info.len + symbol;
	}
	return (len);
}

ssize_t	ft_printfintp(t_info info, int symbol, t_flags flags)
{
	ssize_t	len;

	if (info.size.precision == 0 && info.nbr == 0)
		info.len = 0;
	if (info.size.precision > info.len)
		len = ft_printfintpp(info, symbol, flags);
	else
		len = ft_printfintnp(info, symbol, flags);
	return (len);
}
