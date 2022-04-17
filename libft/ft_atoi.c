/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/17 17:31:24 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	j;
	int	num;

	j = 0;
	sign = 1;
	num = 0;
	while (*(nptr + j) == ' ' || *(nptr + j) == '\n' || *(nptr + j) == '\t'
		|| *(nptr + j) == '\v' || *(nptr + j) == '\f'
		|| *(nptr + j) == '\r')
		j++;
	if (*(nptr + j) == '-')
	{
		sign = sign * (-1);
		j++;
	}
	else if (*(nptr + j) == '+')
		j++;
	while (*(nptr + j) >= '0' && *(nptr + j) <= '9')
	{
		num = num * 10 + (*(nptr + j) - '0');
		j++;
	}
	return (num * sign);
}
