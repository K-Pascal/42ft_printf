/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:12 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/12 18:12:06 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

typedef struct s_pos
{
	int	begin;
	int	end;
}	t_pos;

static int	in_set(char const c, char const set[])
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static t_pos	delim_aftertrim(char const s1[], char const set[])
{
	t_pos	delim;

	delim.begin = 0;
	while (s1[delim.begin] != '\0')
	{
		if (!in_set(s1[delim.begin], set))
			break ;
		delim.begin++;
	}
	delim.end = ft_strlen(s1) - 1;
	while (delim.end >= 0)
	{
		if (!in_set(s1[delim.end], set))
			break ;
		delim.end--;
	}
	return (delim);
}

static char	*ft_strndup_delim(char const s1[], t_pos delim)
{
	char	*str;
	int		i;

	if (delim.begin > delim.end)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc((delim.end - delim.begin + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (delim.begin + i <= delim.end)
	{
		str[i] = s1[delim.begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const s1[], char const set[])
{
	char	*str;
	t_pos	delim;

	delim = delim_aftertrim(s1, set);
	str = ft_strndup_delim(s1, delim);
	return (str);
}
