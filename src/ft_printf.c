/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:29:21 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/09 17:12:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfchars.h"
#include "ft_printfints.h"
#include "ft_printfutils.h"

static ssize_t	ft_printf_fail(char const str[], t_flags flags, t_nums info)
{
	ssize_t	len;

	len = -1;
	if (*str != '\0')
	{
		len = write(1, "%", 1);
		if (flags & ALTERNATE_FORM)
			len += write(1, "#", 1);
		if (flags & SIGN_SYMBOL)
			len += write(1, "+", 1);
		if (flags & LEFT_JUSTIFY)
			len += write(1, "-", 1);
		if (info.width > 0)
		{
			ft_putunbr(info.width, 10, 0);
			len += get_numudigits(info.width, 10);
		}
		if (flags & PRECISION_DEFINED)
		{
			write(1, ".", 1);
			ft_putunbr(info.precision, 10, 0);
			len += get_numudigits(info.precision, 10) + 1;
		}
	}
	return (len);
}

ssize_t	ft_printf_format(char const c, t_flags flags, t_nums info, va_list ap)
{
	ssize_t	len;

	if (c == 'c')
		len = ft_printfchar(ap, flags, info.width);
	else if (c == 's')
		len = ft_printfstr(ap, flags, info.width, info.precision);
	else if (c == 'p')
		len = ft_printfptr(ap, flags, info.width);
	else if (c == 'd' || c == 'i')
		len = ft_printfint(ap, flags, info.width, info.precision);
	else if (c == 'u')
		len = ft_printfuint(ap, flags, info.width, info.precision);
	else if (c == 'x')
		len = ft_printfhex(ap, flags, info.width, info.precision);
	else if (c == 'X')
		len = ft_printfhexu(ap, flags, info.width, info.precision);
	else if (c == '%')
		len = write(1, "%", 1);
	else
		len = -1;
	return (len);
}

static ssize_t	ft_printf_transform(char const *format[], va_list args)
{
	ssize_t	len;
	t_flags	flags;
	t_nums	info;

	flags = ft_printf_getflags(format);
	if (**format == '*')
	{
		info.width = va_arg(args, t_uint);
		(*format)++;
	}
	else
		info.width = ft_printf_atoi(format);
	if (**format == '.')
	{
		(*format)++;
		flags |= PRECISION_DEFINED;
		if (**format == '*')
		{
			info.precision = va_arg(args, t_uint);
			(*format)++;
		}
		else
			info.precision = ft_printf_atoi(format);
	}
	len = ft_printf_format(**format, flags, info, args);
	if (len == -1)
	{
		len = ft_printf_fail(*format, flags, info);
		if (len != -1)
			len += write(1, *format, 1);
	}
	return (len);
}

ssize_t	ft_printf_do(char const *fmt[], va_list ap, ssize_t len_total)
{
	ssize_t	len;

	len = ft_printf_transform(fmt, ap);
	if (len != -1)
	{
		len_total += len;
		(*fmt)++;
	}
	else
		len_total = -1;
	return (len_total);
}

int	ft_printf(char const format[], ...)
{
	va_list	args;
	int		i;
	ssize_t	len_total;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	len_total = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			i++;
		else
		{
			len_total += write(1, format, i);
			format += i + 1;
			len_total = ft_printf_do(&format, args, len_total);
			i = 0;
		}
	}
	if (len_total != -1)
		len_total += write(1, format, i);
	va_end(args);
	return (len_total);
}
