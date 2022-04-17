/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_fdf *fdf, t_point p_a, t_point p_b)
{
	float	dx;
	float	dy;
	int		steps;
	int		iterator;
	t_color	*color;

	steps = calculate_amount_steps(&dx, &dy, p_a, p_b);
	color = initialize_color(p_a, p_b);
	if (!color)
		destroy_everything(fdf, COLOR_INIT_ERROR);
	iterator = 0;
	while (iterator < steps)
	{
		p_a.color = get_color(color, iterator, steps);
		if (is_out_of_bounds(p_a) == IN_BOUNDS)
			allocate_pixel_to_image(fdf->image, p_a, p_a.color);
		p_a.x += dx;
		p_a.y += dy;
		iterator++;
	}
	free(color);
}
