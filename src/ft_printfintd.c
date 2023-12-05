/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfintd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:19:40 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/15 17:26:02 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printf_utils.h"

ssize_t	ft_printfintd(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	int		nbr;
	ssize_t	len;
	char	padding;
	int		additional;
	int		index;

	nbr = va_arg(ap, int);
	len = get_numdigits(nbr, 10);
	additional = (nbr < 0 || flags & SIGN_SYMBOL)
		|| (nbr >= 0 && flags & SPACE_SIGN);
	padding = ' ';
	index = 0;
	if (!(flags & LEFT_JUSTIFY) && flags & ZERO_PADDING)
		padding = '0';
	if (precision == -1)
	{
		len += additional;
		if (width > len)
		{
			if (padding == ' ')
				if (!(flags & LEFT_JUSTIFY))
					padding_char(width - len, padding);
			if (nbr >= 0)
			{
				if (flags & SIGN_SYMBOL)
					write(1, "+", 1);
				else if (flags & SPACE_SIGN)
					write(1, " ", 1);
			}
			if (padding == '0')
				if (!(flags & LEFT_JUSTIFY))
					padding_char(width - len, padding);
			ft_putnbr(nbr, &index, -1);
			if (flags & LEFT_JUSTIFY)
				padding_char(width - len, ' ');
			len = width;
		}
		else
		{
			if (nbr >= 0)
			{
				if (flags & SIGN_SYMBOL)
					write(1, "+", 1);
				else if (flags & SPACE_SIGN)
					write(1, " ", 1);
			}
			ft_putnbr(nbr, &index, -1);
		}
	}
	else
	{
		if (precision >= len)
			len = precision;
		if (width > len + additional)
		{
			if (padding == ' ')
			{
				if (!(flags & LEFT_JUSTIFY))
					padding_char(width - (len + additional), padding);
			}
			if (precision == 0 && nbr == 0)
				write(1, " ", 1);
			if (nbr >= 0)
			{
				if (flags & SIGN_SYMBOL)
					write(1, "+", 1);
				else if (flags & SPACE_SIGN)
					write(1, " ", 1);
			}
			if (padding == '0')
			{
				if (!(flags & LEFT_JUSTIFY))
				{
					if (precision != 0 && nbr != 0)
						padding_char(width - (len + additional), padding);
					else
						padding_char(width - additional, ' ');
				}
			}
			if (precision != 0 || nbr != 0)
				ft_putnbr(nbr, &index, len);
			if (flags & LEFT_JUSTIFY)
				padding_char(width - (len + additional), ' ');
			len = width;
		}
		else
		{
			if (nbr >= 0)
			{
				if (flags & SIGN_SYMBOL)
					write(1, "+", 1);
				else if (flags & SPACE_SIGN)
					write(1, " ", 1);
			}
			ft_putnbr(nbr, &index, len);
			len += additional;
		}
	}
	return (len);
}
