/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rasterize(t_fdf *fdf)
{
	t_point	p;
	int		maximum_width;
	int		maximum_height;

	maximum_width = fdf->landscape->horizontal_boundaries;
	maximum_height = fdf->landscape->vertical_boundaries;
	clear_image(fdf->image, MAX_PIXEL * 4);
	p.y = 0;
	while (p.y < maximum_height)
	{
		p.x = 0;
		while (p.x < maximum_width)
		{
			check_and_plot(fdf, p, fdf->landscape->cartesian_plane);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->image->img_ptr, 0,
		0);
	show_instructions(fdf);
}

void	check_and_plot(t_fdf *fdf, t_point p, t_point **cartesian_plane)
{
	int	i;
	int	j;

	i = p.x;
	j = p.y;
	if (i < fdf->landscape->horizontal_boundaries - 1)
		rasterize_vector(fdf, cartesian_plane[i][j], cartesian_plane[i + 1][j]);
	if (j < fdf->landscape->vertical_boundaries - 1)
		rasterize_vector(fdf, cartesian_plane[i][j], cartesian_plane[i][j + 1]);
}

void	rasterize_vector(t_fdf *fdf, t_point p_a, t_point p_b)
{
	p_a.z *= fdf->pov->params.depth_scale;
	p_b.z *= fdf->pov->params.depth_scale;
	colorfy_point(fdf, &p_a);
	colorfy_point(fdf, &p_b);
	fdf->image->vector = initialize_vector(p_a, p_b, fdf->landscape);
	if (!fdf->image->vector)
		close_all(fdf, 7);
	rotate(fdf->pov, fdf->image->vector);
	project(fdf->pov, fdf->image->vector);
	transform(fdf->pov, fdf->image->vector);
	draw_line(fdf, fdf->image->vector->p_a, fdf->image->vector->p_b);
	free(fdf->image->vector);
}
