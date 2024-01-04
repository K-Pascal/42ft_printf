/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:29:05 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/04 10:17:40 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"

static ssize_t	ft_printfhexnull(t_flags flags, t_nums size)
{
	ssize_t	len;

	len = 5;
	if (size.width > len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(size.width - len, ' ');
		write(1, "(nil)", 5);
		if (flags & LEFT_JUSTIFY)
			padding_char(size.width - len, ' ');
		len = size.width;
	}
	else
		write(1, "(nil)", 5);
	return (len);
}

ssize_t	ft_printfptr(va_list ap, t_flags flags, t_nums size)
{
	void			*ptr;
	ssize_t			len;
	unsigned long	lptr;

	ptr = va_arg(ap, void *);
	if (ptr == 0)
		return (ft_printfhexnull(flags, size));
	lptr = (unsigned long)ptr;
	len = get_numudigits(lptr, 16) + 2;
	if (size.width > len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(size.width - len, ' ');
		write(1, "0x", 2);
		ft_putunbr(lptr, 16, 0, len - 2);
		if (flags & LEFT_JUSTIFY)
			padding_char(size.width - len, ' ');
		len = size.width;
	}
	else
	{
		write(1, "0x", 2);
		ft_putunbr(lptr, 16, 0, len - 2);
	}
	return (len);
}
