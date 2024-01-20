/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:59 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:32:00 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "ft_printfints.h"
#include "ft_printfutils.h"
#include "typedefs.h"

static ssize_t	ft_printfuintpp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.size.precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - info.size.precision, ' ');
		padding_char(info.size.precision - info.len, '0');
		ft_putunbr(info.nbr, 10, 0, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - info.size.precision, ' ');
		len = info.size.width;
	}
	else
	{
		padding_char(info.size.precision - info.len, '0');
		ft_putunbr(info.nbr, 10, 0, info.len);
		len = info.size.precision;
	}
	return (len);
}

static ssize_t	ft_printfuintnp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - info.len, ' ');
		if (info.len > 0)
			ft_putunbr(info.nbr, 10, 0, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - info.len, ' ');
		len = info.size.width;
	}
	else
	{
		if (info.len > 0)
			ft_putunbr(info.nbr, 10, 0, info.len);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfuintn(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.size.width > info.len)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - info.len, ' ');
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.size.width - info.len, '0');
		ft_putunbr(info.nbr, 10, 0, info.len);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.size.width - info.len, ' ');
		len = info.size.width;
	}
	else
	{
		ft_putunbr(info.nbr, 10, 0, info.len);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfuintp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.size.precision == 0 && info.nbr == 0)
		info.len = 0;
	if (info.size.precision > info.len)
		len = ft_printfuintpp(info, flags);
	else
		len = ft_printfuintnp(info, flags);
	return (len);
}
