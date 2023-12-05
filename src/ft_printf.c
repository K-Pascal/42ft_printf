/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:29:21 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/15 18:47:23 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printf_chars.h"
#include "ft_printf_ints.h"

int	ft_printf(char const format[], ...)
{
	va_list			args;
	int				i;
	t_flags			flags;
	ssize_t			len;
	uint			width;
	ssize_t			precision;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	flags = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			i++;
		else
		{
			len += write(1, format, i);
			format += i;
			i = 1;
			flags = get_flags(format + i, &i);
			width = get_width(format + i, &i);
			precision = -1;
			if (format[i] == '.')
			{
				i++;
				precision = get_width(format + i, &i);
			}
			if (format[i] == 'c')
				len += ft_printfchar(args, flags, width);
			else if (format[i] == 's')
				len += ft_printfstr(args, flags, width, precision);
			else if (format[i] == 'p')
				len += ft_printfptr(args, flags, width);
			else if (format[i] == 'd' || format[i] == 'i')
				len += ft_printfintd(args, flags, width, precision);
			else if (format[i] == 'u')
			{
			}
			else if (format[i] == 'x')
			{
			}
			else if (format[i] == 'X')
			{
			}
			else if (format[i] == '%')
				len += write(1, "%", 1);
			else
				len += write(1, format, i + 1);
			format += i + 1;
			i = 0;
		}
	}
	len += write(1, format, i);
	va_end(args);
	return (len);
}
