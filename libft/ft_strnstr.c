/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:36:12 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/11 13:36:14 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (!*little)
		return ((char *)big);
	while (*(big + b) && b < len)
	{
		l = 0;
		while (*(little + l) == *(big + b + l) && b + l < len)
		{
			if (!*(little + l + 1))
				return ((char *)big + b);
			l++;
		}
		b++;
	}
	return (NULL);
}
