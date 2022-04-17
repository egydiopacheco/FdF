/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:57 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/11 13:35:58 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;

	j = ft_strlen(src);
	if (size == 0)
		return (j);
	size = size - 1;
	while (*src && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (j);
}
