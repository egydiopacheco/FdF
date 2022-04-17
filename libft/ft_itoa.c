/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:34:12 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/15 01:11:07 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_amount(long n)
{
	long	size;

	size = 0;
	if (n <= 0)
	{
		n = n * (-1);
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*c;
	long		x;
	int			k;

	x = n;
	k = digit_amount(x);
	c = (char *)malloc(sizeof(char) * (k + 1));
	if (!c)
		return (NULL);
	*(c + k--) = '\0';
	if (x < 0)
	{
		*(c + 0) = '-';
		x = x * (-1);
	}
	else if (x == 0)
		*(c + 0) = '0';
	while (x > 0)
	{
		*(c + k--) = 48 + (x % 10);
		x = x / 10;
	}
	return (c);
}
