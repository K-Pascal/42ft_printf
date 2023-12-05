/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:37:03 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/17 15:24:04 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <sys/types.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfints.h"
#include "ft_printfint.h"

ssize_t	ft_printfint(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	t_info	info;
	ssize_t	len;
	int		symbol;

	info.nbr = va_arg(ap, int);
	info.len = get_numdigits(info.nbr, 10);
	info.width = width;
	info.precision = precision;
	symbol = 0;
	if (info.nbr < 0 || flags & SIGN_SYMBOL
		|| (flags & SPACE_SIGN && (info.nbr >= 0 || flags & ZERO_PADDING)))
		symbol = 1;
	if (info.precision == -1)
		len = ft_printfintn(info, symbol, flags);
	else
		len = ft_printfintp(info, symbol, flags);
	return (len);
}
