/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:00:17 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 18:21:29 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <sys/types.h>
#include "ft_printfparser.h"

typedef unsigned int uint;

int		ft_printf(char const format[], ...);
void	padding_space(unsigned int len);
ssize_t	ft_printfchar(va_list ap, t_flags, uint width);
ssize_t	ft_printfstr(va_list ap, t_flags, uint width, ssize_t precision);

#endif
