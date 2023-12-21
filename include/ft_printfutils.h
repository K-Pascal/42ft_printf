/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:33 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/21 17:41:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFUTILS_H
# define FT_PRINTFUTILS_H

# include <sys/types.h>

# include "ft_printf.h"

void	padding_char(ssize_t len, char c);
int		get_numudigits(unsigned long nbr, int base);
int		get_numdigits(int nbr, int base);
void	ft_putnbr(int nbr, ssize_t len);
void	ft_putunbr(unsigned long nbr, unsigned int base, int uppercase, ssize_t len);

#endif
