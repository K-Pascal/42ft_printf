/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:33:52 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:34:22 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "libft/libft.h"

#include "ft_printfutils.h"
#include "typedefs.h"

ssize_t	ft_printfnullstr(t_flags flags, t_nums size)
{
	if (flags & PRECISION_DEFINED && size.precision < 6)
		size.precision = 0;
	else if (!(flags & PRECISION_DEFINED) || size.precision > 6)
		size.precision = 6;
	if (size.width > size.precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(size.width - size.precision, ' ');
		write(1, "(null)", size.precision);
		if (flags & LEFT_JUSTIFY)
			padding_char(size.width - size.precision, ' ');
	}
	else
	{
		write(1, "(null)", size.precision);
		return (size.precision);
	}
	return (size.width);
}

ssize_t	ft_printfchar(va_list ap, t_flags flags, t_nums size)
{
	char	c;
	ssize_t	len;

	c = va_arg(ap, int);
	len = 0;
	if (size.width > 1)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(size.width - 1, ' ');
		len += write(1, &c, 1);
		if (flags & LEFT_JUSTIFY)
			padding_char(size.width - 1, ' ');
		len += size.width - 1;
	}
	else
		len += write(1, &c, 1);
	return (len);
}

ssize_t	ft_printfstr(va_list ap, t_flags flags, t_nums size)
{
	char const	*str;
	size_t		len_s;
	ssize_t		len;

	len = 0;
	str = va_arg(ap, char const *);
	if (str == 0)
		return (ft_printfnullstr(flags, size));
	len_s = ft_strlen(str);
	if (!(flags & PRECISION_DEFINED) || len_s < size.precision)
		size.precision = len_s;
	if (size.width > size.precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(size.width - size.precision, ' ');
		len += write(1, str, size.precision);
		if (flags & LEFT_JUSTIFY)
			padding_char(size.width - size.precision, ' ');
		len += size.width - size.precision;
	}
	else
		len += write(1, str, size.precision);
	return (len);
}
