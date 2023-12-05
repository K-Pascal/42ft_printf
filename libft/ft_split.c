/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:28:42 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/12 18:14:53 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_pos {
	int	begin;
	int	end;
}t_pos;

static int	count_words(char const s[], char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			j = 1;
			while (s[i + j] != c)
			{
				if (s[i + j] == '\0')
					return (count);
				j++;
			}
			i += j;
		}
		else
			i++;
	}
	return (count);
}

static t_pos	next_word(char const s[], char c, int pos)
{
	t_pos	delim;

	delim.begin = 0;
	delim.end = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
		{
			delim.begin = pos;
			while (s[pos] != c)
			{
				if (s[pos] == '\0')
					break ;
				pos++;
			}
			delim.end = pos - 1;
			break ;
		}
		else
			pos++;
	}
	return (delim);
}

static char	*ft_strdup_delim(char const s[], t_pos delim)
{
	char	*str;
	int		i;

	str = malloc((delim.end - delim.begin + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (delim.begin + i <= delim.end)
	{
		str[i] = s[delim.begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	my_free_all(char **arr, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const s[], char c)
{
	char	**arr_str;
	int		num_words;
	int		i;
	t_pos	delim;

	num_words = count_words(s, c);
	arr_str = malloc((num_words + 1) * sizeof(char *));
	if (arr_str == NULL)
		return (NULL);
	i = 0;
	delim.begin = 0;
	while (i < num_words)
	{
		delim = next_word(s, c, delim.begin);
		arr_str[i] = ft_strdup_delim(s, delim);
		if (arr_str[i] == NULL)
		{
			my_free_all(arr_str, i);
			return (NULL);
		}
		delim.begin = delim.end + 1;
		i++;
	}
	arr_str[i] = NULL;
	return (arr_str);
}
