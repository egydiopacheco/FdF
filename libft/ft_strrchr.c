/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:36:17 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/15 01:10:47 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
		p++;
	if (c == '\0')
		return (p);
	while (p >= s)
	{
		if (*p == (char)c)
			return (p);
		p--;
	}
	return (NULL);
}
