/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:28 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/15 21:01:29 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_amount(char const *s, char c)
{
	char	flag;
	size_t	amount;

	flag = 'F';
	amount = 0;
	while (*s)
	{
		if (*s == c)
			flag = 'F';
		else if (flag == 'F')
		{
			flag = 'T';
			amount++;
		}
		s++;
	}
	return (amount);
}

static size_t	get_upper_bound(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (*(s + j) && *(s + j) != c)
		j++;
	return (j);
}

static char	**synthetize_array(char const *s, char c, char **arr)
{
	size_t	k;
	size_t	start;
	size_t	end;

	start = 0;
	k = 0;
	while (*(s + start))
	{
		if (*(s + start) != c)
		{
			end = get_upper_bound(s + start, c);
			*(arr + k) = ft_substr(s, start, end);
			start = (start + end - 1);
			k++;
		}
		start++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)ft_calloc(get_amount(s, c) + 1, sizeof(char *));
	if (!arr)
		return (0);
	return (synthetize_array(s, c, arr));
}
