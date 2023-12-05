/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:32:23 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/11 20:09:33 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

size_t	ft_strlcat(char dst[], const char src[], size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	j;

	len_s = ft_strlen(src);
	if (size == 0)
		return (size + len_s);
	len_d = ft_strlen(dst);
	if (len_d < size)
	{
		j = 0;
		while (src[j] != '\0')
		{
			if (j + len_d + 1 >= size)
				break ;
			dst[len_d + j] = src[j];
			j++;
		}
		dst[len_d + j] = '\0';
		return (len_d + len_s);
	}
	return (size + len_s);
}
