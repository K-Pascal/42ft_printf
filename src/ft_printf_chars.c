/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:33:52 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 17:42:03 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/libft.h"
#include "ft_printf.h"

ssize_t	ft_printfnullstr(t_flags flags, uint width, uint precision)
{
	if (precision < 6)
		precision = 0;
	if (width > precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_space(width - precision);
		write(1, "(null)", precision);
		if (flags & LEFT_JUSTIFY)
			padding_space(width - precision);
	}
	return (width);
}

ssize_t	ft_printfchar(va_list ap, t_flags flags, uint width)
{
	char	c;
	ssize_t	len;

	c = va_arg(ap, int);
	len = 0;
	if (width > 1)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_space(width - 1);
		len += write(1, &c, 1);
		if (flags & LEFT_JUSTIFY)
			padding_space(width - 1);
		len += width - 1;
	}
	else
		len += write(1, &c, 1);
	return (len);
}

ssize_t	ft_printfstr(va_list ap, t_flags flags, uint width, uint precision)
{
	char		*str;
	size_t		len_s;
	ssize_t		len;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		return (ft_printfnullstr(flags, width, precision));
	len_s = ft_strlen(str);
	if (len_s < precision)
		precision = len_s;
	if (width > precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_space(width - precision);
		len += write(1, str, precision);
		if (flags & LEFT_JUSTIFY)
			padding_space(width - precision);
		len += width - precision;
	}
	else
		len += write(1, str, precision);
	return (len);
}
