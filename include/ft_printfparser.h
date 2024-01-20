/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfparser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:07 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:33:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFPARSER_H
# define FT_PRINTFPARSER_H

# include "typedefs.h"

t_flags	ft_printf_getflags(char const *str[]);
t_uint	ft_printf_atoi(char const *str[]);
#endif
