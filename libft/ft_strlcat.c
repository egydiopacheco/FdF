/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:52 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/15 01:34:13 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	j;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dst);
	if (!size || dest_size > size)
		return (src_size + size);
	j = 0;
	while (*(src + j) && (j + dest_size) < (size - 1))
	{
		*(dst + dest_size + j) = *(src + j);
		j++;
	}
	*(dst + dest_size + j) = '\0';
	return (dest_size + src_size);
}
