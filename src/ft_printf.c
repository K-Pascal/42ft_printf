/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:29:21 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 15:28:55 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/*
char	*ft_strndup(char const *src, size_t len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (str != 0)
		ft_strlcpy(str, src, len + 1);
	return (str);
}
*/

#include "ftprintf_parser.h"
#include "libft/libft.h"

void	padding_space(unsigned int len)
{
	while (len-- > 0)
		write(1, " ", 1);
}

ssize_t	ft_printfchar(va_list ap, t_flags flags, unsigned int width)
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

ssize_t	ft_printfstr(va_list ap, t_flags flags, unsigned int width, unsigned int precision)
{
	char *str;
	size_t		len_s;
	ssize_t		len;

	len = 0;
	str = va_arg(ap, char *);
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

int	ft_printf(char const format[], ...)
{
	va_list		args;
	int			i;
	t_flags		flags;
	ssize_t		len;
	unsigned int	width;
	unsigned int 	precision;

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
			flags = get_flags(&(format[i]), &i);
			width = get_width(&(format[i]), &i);
			precision = 0;
			if (format[i] == '.')
			{
				i++;
				precision = get_width(&(format[i]), &i);
			}
			if (format[i] == 'c')
				len += ft_printfchar(args, flags, width);
			else if (format[i] == 's')
				len += ft_printfstr(args, flags, width, precision);
			else if (format[i] == 'p')
			{
			}
			else if (format[i] == 'd')
			{
			}
			else if (format[i] == 'i')
			{
			}
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
			{
				len += write(1, "%", 1);
			}
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
