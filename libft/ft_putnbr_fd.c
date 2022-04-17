/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:18 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/11 13:35:20 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		correction;
	int		digit;
	char	c;

	correction = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			n = n + 1;
			n = n * (-1);
			correction = 1;
		}
		else
			n = n * (-1);
	}
	if (n > 9)
	{
		digit = n / 10;
		ft_putnbr_fd(digit, fd);
	}
	n = (n % 10) + correction;
	c = n + '0';
	write(fd, &c, 1);
}
