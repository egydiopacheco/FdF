/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	centralize(t_landscape *landscape)
{
	int	x;
	int	y;

	y = 0;
	while (y < landscape->vertical_boundaries)
	{
		x = 0;
		while (x < landscape->horizontal_boundaries)
		{
			landscape->cartesian_plane[x][y].x
				-= landscape->horizontal_boundaries / 2;
			landscape->cartesian_plane[x][y].y -= landscape->vertical_boundaries
				/ 2;
			x++;
		}
		y++;
	}
}

float	fit_screen(t_landscape *landscape)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WINDOW_WIDTH / landscape->horizontal_boundaries;
	scale_y = WINDOW_HEIGHT / landscape->vertical_boundaries;
	scale_factor = ft_min_value_between(scale_x, scale_y);
	if (scale_factor < 3.85)
		return (1.25);
	return (scale_factor / 3.75);
}
