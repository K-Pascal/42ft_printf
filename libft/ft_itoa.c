/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:18 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/09 19:09:18 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n < 0 || n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	reverse_str(char str[])
{
	int		i;
	char	temp;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*digits;
	int		len;
	int		i;

	len = num_digits(n);
	i = 0;
	if (n < 0)
		i = 1;
	digits = ft_calloc(len + i + 1, sizeof(char));
	if (digits == 0)
		return (0);
	if (n < 0)
		digits[len] = '-';
	i = 0;
	while (i < len)
	{
		if (n < 0)
			digits[i] = -(n % 10) + '0';
		else
			digits[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	reverse_str(digits);
	return (digits);
}
