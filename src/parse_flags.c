/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:14:08 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 17:42:34 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfparser.h"

t_flags	get_flags(char const str[], int *i)
{
	t_flags	flags;
	t_flags	newflags;

	flags = 0;
	while (1)
	{
		newflags = 0;
		if (*str == '-')
			newflags |= LEFT_JUSTIFY;
		else if (*str == '+')
			newflags |= SIGN_SYMBOL;
		else if (*str == ' ')
			newflags |= SPACE_SIGN;
		else if (*str == '#')
			newflags |= ALTERNATE_FORM;
		else if (*str == '0')
			newflags |= ZERO_PADDING;
		if (newflags == 0)
			break ;
		(*i)++;
		flags = newflags;
		str++;
	}
	return (flags);
}

unsigned int	get_width(char const str[], int *i)
{
	unsigned int	nbr;

	nbr = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
		(*i)++;
	}
	return (nbr);
}
