/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:36:23 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/15 14:04:09 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	max_copy;

	if (!s)
		return (NULL);
	max_copy = len + 1;
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	else if (start + len > size)
		max_copy = (size - start) + 1;
	substr = (char *)malloc((max_copy * sizeof(char)));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, max_copy);
	return (substr);
}
