/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:39:17 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/12 18:10:37 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const s1[], char const s2[])
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(size, sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcat(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
