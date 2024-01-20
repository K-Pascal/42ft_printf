/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfints.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:32:03 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:28:47 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFINTS_H
# define FT_PRINTFINTS_H

# include <stdarg.h>
# include <sys/types.h>

# include "typedefs.h"

ssize_t	ft_printfptr(va_list ap, t_flags flags, t_nums size);
ssize_t	ft_printfint(va_list ap, t_flags flags, t_nums size);
ssize_t	ft_printfuint(va_list ap, t_flags flags, t_nums size);
ssize_t	ft_printfhex(va_list ap, t_flags flags, t_nums size);
ssize_t	ft_printfhexu(va_list ap, t_flags flags, t_nums size);
#endif
