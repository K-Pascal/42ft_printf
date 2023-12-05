/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ints.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:32:03 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/15 11:53:53 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTS_H
# define FT_PRINTF_INTS_H

#include "ft_printf.h"
#include "ft_printfparser.h"

ssize_t	ft_printfhexnull(t_flags flags, uint width);
ssize_t	ft_printfptr(va_list ap, t_flags flags, uint width);
#endif
