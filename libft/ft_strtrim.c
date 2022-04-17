/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:36:20 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/11 13:36:21 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;

	if (!s1)
		return (NULL);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	j = ft_strlen(s1);
	while (j)
	{
		if (!ft_strchr(set, *(s1 + j)))
			break ;
		j--;
	}
	return (ft_substr(s1, 0, j + 1));
}
