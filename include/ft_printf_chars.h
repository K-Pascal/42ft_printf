/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:46 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/15 11:40:43 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CHARS_H
# define FT_PRINTF_CHARS_H

#include <sys/types.h>
#include <stdarg.h>

#include "ft_printf.h"
#include "ft_printfparser.h"

ssize_t	ft_printfchar(va_list ap, t_flags, uint width);
ssize_t	ft_printfstr(va_list ap, t_flags, uint width, ssize_t precision);

#endif
