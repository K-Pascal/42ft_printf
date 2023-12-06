/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:00:17 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 20:22:50 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef unsigned int	t_uint;

typedef struct s_nums
{
	t_uint	width;
	ssize_t	precision;
}	t_nums;

int		ft_printf(char const format[], ...);

#endif
