/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchars.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:46 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:28:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFCHARS_H
# define FT_PRINTFCHARS_H

# include <sys/types.h>
# include <stdarg.h>

# include "typedefs.h"

ssize_t	ft_printfchar(va_list ap, t_flags flags, t_nums info);
ssize_t	ft_printfstr(va_list ap, t_flags flags, t_nums info);

#endif
