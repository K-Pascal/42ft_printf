/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:33 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/18 14:15:22 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

#include "ft_printf.h"

void	padding_char(unsigned int len, char c);
void	ft_putunbr(unsigned long nbr, unsigned int base, int uppercase);
int		get_numudigits(unsigned long nbr, int base);
int		get_numdigits(int nbr, int base);
void	ft_putnbr(int nbr);

#endif
