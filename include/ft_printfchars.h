/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchars.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:46 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/09 17:00:13 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFCHARS_H
# define FT_PRINTFCHARS_H

# include <sys/types.h>
# include <stdarg.h>

# include "ft_printf.h"
# include "ft_printfparser.h"

ssize_t	ft_printfchar(va_list ap, t_flags flags, t_nums info);
ssize_t	ft_printfstr(va_list ap, t_flags flags, t_nums info);

#endif
