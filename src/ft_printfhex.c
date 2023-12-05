/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:43:41 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/18 15:47:48 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"
#include "ft_printfints.h"

static ssize_t	ft_printfhexpp(t_uinfo info, t_flags flags, int uppercase)
{
	ssize_t	len;

	if (info.width > info.precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.precision, ' ');
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 16, uppercase);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.precision, ' ');
		len = info.width;
	}
	else
	{
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 16, uppercase);
		len = info.precision;
	}
	return (len);
}

static ssize_t	ft_printfhexnn(t_uinfo info, t_flags flags, int uppercase)
{
	ssize_t	len;

	if (info.width >= info.len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, ' ');
		if (info.precision != 0 || info.nbr != 0)
			ft_putunbr(info.nbr, 16, uppercase);
		else
			write(1, " ", 1);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.len, ' ');
		len = info.width;
	}
	else
	{
		if (info.precision != 0 || info.nbr != 0)
			ft_putunbr(info.nbr, 16, uppercase);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfhexn(t_uinfo info, t_flags flags, int uppercase)
{
	ssize_t	len;

	if (info.width > info.len)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, ' ');
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, '0');
		ft_putunbr(info.nbr, 16, uppercase);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.len, ' ');
		len = info.width;
	}
	else
	{
		ft_putunbr(info.nbr, 16, uppercase);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfhexp(t_uinfo info, t_flags flags, int uppercase)
{
	ssize_t	len;
	int		index;

	index = 0;
	if (info.precision > info.len)
		len = ft_printfhexpp(info, flags, uppercase);
	else
		len = ft_printfhexnn(info, flags, uppercase);
	return (len);
}
