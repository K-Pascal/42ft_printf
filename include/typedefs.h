/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:25:50 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/20 19:33:47 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <sys/types.h>

typedef unsigned int	t_uint;

typedef struct s_nums
{
	t_uint	width;
	t_uint	precision;
}	t_nums;

typedef enum e_flags
{
	LEFT_JUSTIFY = (1 << 0),
	SIGN_SYMBOL = (1 << 1),
	SPACE_SIGN = (1 << 2),
	ALTERNATE_FORM = (1 << 3),
	ZERO_PADDING = (1 << 4),
	PRECISION_DEFINED = (1 << 5)
}	t_flags;

typedef struct s_info
{
	int		nbr;
	ssize_t	len;
	t_nums	size;
}	t_info;

typedef struct s_uinfo
{
	t_uint	nbr;
	ssize_t	len;
	t_nums	size;
}	t_uinfo;

#endif 
