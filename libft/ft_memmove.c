/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:02 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/14 10:58:38 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	j;

	if (!src && !dest)
		return (NULL);
	if ((char *)dest > (char *)src)
	{
		j = n - 1;
		while (n--)
		{
			*((char *)dest + j) = *((char *)src + j);
			j--;
		}
	}
	else
	{
		j = 0;
		while (j < n)
		{
			*((char *)dest + j) = *((char *)src + j);
			j++;
		}
	}
	return (dest);
}
