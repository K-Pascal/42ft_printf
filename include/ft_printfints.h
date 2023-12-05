/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfints.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:32:03 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/17 15:33:10 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTS_H
# define FT_PRINTF_INTS_H

#include <stdarg.h>
#include <sys/types.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"

typedef struct s_info
{
	int		nbr;
	ssize_t	len;
	t_uint	width;
	ssize_t	precision;
}	t_info;

ssize_t	ft_printfptr(va_list ap, t_flags flags, t_uint width);
ssize_t	ft_printfint(va_list ap, t_flags flags, t_uint width, ssize_t precision);
#endif
