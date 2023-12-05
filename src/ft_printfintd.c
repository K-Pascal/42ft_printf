/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfintd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:19:40 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/16 17:25:31 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printf_utils.h"

void	ft_printfintd_symbol(int nbr, t_flags flags)
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

ssize_t	ft_printfintd_normal(int nbr, t_flags flags, t_uint width, ssize_t len)
{
	int		index;

	index = 0;
	if (width > len)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(width - len, ' ');
		ft_printfintd_symbol(nbr, flags);
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(width - len, '0');
		ft_putnbr(nbr, &index, -1);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - len, ' ');
		len = width;
	}
	else
	{
		ft_printfintd_symbol(nbr, flags);
		ft_putnbr(nbr, &index, -1);
	}
	return (len);
}

ssize_t	ft_printfintd_precision(int nbr, t_flags flags, t_uint width, ssize_t precision)
{
	ssize_t	len;
	int		index;
	int		additional;

	len = get_numdigits(nbr, 10);
	additional = nbr < 0 || flags & SIGN_SYMBOL
		|| (flags & SPACE_SIGN && (nbr >= 0 || flags & ZERO_PADDING));
	index = 0;
	if (precision > len)
	{
		if (width > precision + additional)
		{
			if (!(flags & LEFT_JUSTIFY))
					padding_char(width - (precision + additional), ' ');
			ft_printfintd_symbol(nbr, flags);
			padding_char(precision - len, '0');
			ft_putnbr(nbr, &index, len);
			if (flags & LEFT_JUSTIFY)
				padding_char(width - (precision + additional), ' ');
			len = width;
		}
		else
		{
			ft_printfintd_symbol(nbr, flags);
			padding_char(precision - len, '0');
			ft_putnbr(nbr, &index, len);
			len = precision + additional;
		}
	}
	else
	{
		if (width > len + additional)
		{
			if (!(flags & LEFT_JUSTIFY))
					padding_char(width - (len + additional), ' ');
			ft_printfintd_symbol(nbr, flags);
			if (precision != 0 || nbr != 0)
				ft_putnbr(nbr, &index, len);
			if (flags & LEFT_JUSTIFY)
				padding_char(width - (len + additional), ' ');
			len = width;
		}
		else
		{
			ft_printfintd_symbol(nbr, flags);
			if (precision != 0 || nbr != 0)
				ft_putnbr(nbr, &index, len);
			len += additional;
		}
	}
	return (len);
}

ssize_t	ft_printfintd(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	int		nbr;
	ssize_t	len;
	int		additional;

	nbr = va_arg(ap, int);
	len = get_numdigits(nbr, 10);
	additional = nbr < 0 || flags & SIGN_SYMBOL
		|| (flags & SPACE_SIGN && (nbr >= 0 || flags & ZERO_PADDING));
	if (precision == -1)
		len = ft_printfintd_normal(nbr, flags, width, len + additional);
	else
		len = ft_printfintd_precision(nbr, flags, width, precision);
	return (len);
}
