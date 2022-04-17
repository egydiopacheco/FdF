/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	refresh(t_fdf *fdf)
{
	fdf->pov->params.scaling_factor = fit_screen(fdf->landscape);
	fdf->pov->params.depth_scale = 1;
	fdf->pov->pos.x = WINDOW_WIDTH / 1.75;
	fdf->pov->pos.y = WINDOW_HEIGHT / 1.5;
	fdf->pov->params.a = 0;
	fdf->pov->params.b = 0;
	fdf->pov->params.c = 0;
}

void	clear_image(t_image *image, int image_size)
{
	t_point	p;

	ft_bzero(image->address, image_size);
	p.y = 0;
	while (p.y < WINDOW_HEIGHT)
	{
		p.x = 0;
		while (p.x < WINDOW_WIDTH)
		{
			allocate_pixel_to_image(image, p, BACKGROUND);
			p.x++;
		}
		p.y++;
	}
}
