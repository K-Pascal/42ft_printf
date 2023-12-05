/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:24:17 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/11 16:28:28 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char s1[], const char s2[], size_t n)
{
	unsigned char	l1;
	unsigned char	l2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		l1 = s1[i];
		l2 = s2[i];
		if (l1 != l2)
			break ;
		if (l1 == '\0')
			break ;
		i++;
	}
	return (l1 - l2);
}
