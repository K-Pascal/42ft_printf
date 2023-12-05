/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:29:21 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 17:41:25 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "ft_printfparser.h"
#include "ft_printf.h"
#include "libft/libft.h"

void	padding_space(uint len)
{
	while (len-- > 0)
		write(1, " ", 1);
}

void	ft_puthex(unsigned long nbr, int uppercase)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, uppercase);
	if (uppercase)
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
}

int	get_numdigits(unsigned long nbr, int base)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

ssize_t	ft_printfptr(va_list ap, t_flags flags, unsigned int width)
{
	void			*ptr;
	ssize_t			len;
	unsigned long	lptr;

	ptr = va_arg(ap, void *);
	lptr = (unsigned long)ptr;
	len = get_numdigits(lptr, 16) + 2;
	if (width > len)
	{
		if (!(flags && LEFT_JUSTIFY))
			padding_space(width - len);
		write(1, "0x", 2);
		ft_puthex((unsigned long)ptr, 0);
		if (flags && LEFT_JUSTIFY)
			padding_space(width - len);
		len = width;
	}
	else
	{
		write(1, "0x", 2);
		ft_puthex((unsigned long)ptr, 0);
	}
	return (len);
}

int	ft_printf(char const format[], ...)
{
	va_list			args;
	int				i;
	t_flags			flags;
	ssize_t			len;
	unsigned int	width;
	unsigned int	precision;

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
				len += ft_printfptr(args, flags, width);
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
