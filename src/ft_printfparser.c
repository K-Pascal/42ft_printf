/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfparser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:14:08 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/09 16:17:54 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "libft/libft.h"

t_flags	ft_printf_getflags(char const *str[])
{
	t_flags	flags;
	t_flags	newflags;

	flags = 0;
	while (1)
	{
		newflags = 0;
		if (**str == '-')
			newflags |= LEFT_JUSTIFY;
		else if (**str == '+')
			newflags |= SIGN_SYMBOL;
		else if (**str == ' ')
			newflags |= SPACE_SIGN;
		else if (**str == '#')
			newflags |= ALTERNATE_FORM;
		else if (**str == '0')
			newflags |= ZERO_PADDING;
		if (newflags == 0)
			break ;
		flags |= newflags;
		(*str)++;
	}
	return (flags);
}

t_uint	ft_printf_atoi(char const *str[])
{
	t_uint	nbr;

	nbr = 0;
	while (**str && ft_isdigit(**str))
	{
		nbr = nbr * 10 + **str - '0';
		(*str)++;
	}
	return (nbr);
}
