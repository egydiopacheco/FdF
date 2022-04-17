/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	**build_cartesian_plane(int width, int depth)
{
	t_point	**cartesian_plane;
	int		i;
	int		j;

	cartesian_plane = malloc(width * sizeof(t_point *));
	if (!cartesian_plane)
		return (NULL);
	i = 0;
	while (i < width)
	{
		cartesian_plane[i] = malloc(depth * sizeof(t_point));
		if (!cartesian_plane[i])
			return (NULL);
		j = 0;
		while (j < depth)
		{
			cartesian_plane[i][j].x = 0;
			cartesian_plane[i][j].y = 0;
			cartesian_plane[i][j].z = 0;
			cartesian_plane[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (cartesian_plane);
}
