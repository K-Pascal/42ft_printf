/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:48:53 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:28:26 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFHEX_H
# define FT_PRINTFHEX_H

# include "typedefs.h"

ssize_t	ft_printfhexn(t_uinfo info, t_flags flags, int symbol, int uppercase);
ssize_t	ft_printfhexp(t_uinfo info, t_flags flags, int symbol, int uppercase);

#endif
