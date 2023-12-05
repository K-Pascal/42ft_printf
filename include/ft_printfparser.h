/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:07 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/14 13:08:28 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_PARSER_H
# define FTPRINTF_PARSER_H

typedef enum e_flags
{
	LEFT_JUSTIFY = (1 << 0),
	SIGN_SYMBOL = (1 << 1),
	SPACE_SIGN = (1 << 2),
	ALTERNATE_FORM = (1 << 3),
	ZERO_PADDING = (1 << 4)
} t_flags;

t_flags			get_flags(char const str[], int *i);
unsigned int	get_width(char const str[], int *i);
#endif
