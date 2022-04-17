/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	hotkeys_hooks(int key, t_fdf *fdf)
{
	if (key == ESC)
		destroy_everything(fdf, 0);
	else if (key == KEY_D || key == KEY_A || key == KEY_W || key == KEY_S)
		moving_actions(key, fdf);
	else if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT || \
			key == ARROW_RIGHT)
		scaling_actions(key, fdf);
	else if (key == KEY_Q || key == KEY_E || key == KEY_Z || key == KEY_X || \
			key == KEY_C || key == KEY_V)
		rotation_actions(key, fdf);
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3)
		change_projections(key, fdf);
	else if (key == KEY_4)
	{
		if (fdf->pov->color_pallet == false)
			fdf->pov->color_pallet = true;
		else
			fdf->pov->color_pallet = false;
	}
	else if (key == KEY_SPACE)
		refresh(fdf);
	rasterize(fdf);
	return (0);
}

void	moving_actions(int key, t_fdf *fdf)
{
	if (key == KEY_D)
		fdf->pov->pos.x += 10;
	else if (key == KEY_A)
		fdf->pov->pos.x -= 10;
	else if (key == KEY_S)
		fdf->pov->pos.y += 10;
	else if (key == KEY_W)
		fdf->pov->pos.y -= 10;
}

void	scaling_actions(int key, t_fdf *fdf)
{
	if (key == ARROW_UP)
		fdf->pov->params.scaling_factor += 2;
	else if (key == ARROW_DOWN)
		fdf->pov->params.scaling_factor -= 2;
	else if (key == ARROW_LEFT && fdf->pov->params.depth_scale > -1)
		fdf->pov->params.depth_scale -= 0.1;
	else if (key == ARROW_RIGHT && fdf->pov->params.depth_scale < 1)
		fdf->pov->params.depth_scale += 0.1;
}

void	rotation_actions(int key, t_fdf *fdf)
{
	if (key == KEY_Q)
		fdf->pov->params.a -= (5 * DEG_1);
	else if (key == KEY_E)
		fdf->pov->params.a += (5 * DEG_1);
	else if (key == KEY_Z)
		fdf->pov->params.c -= (5 * DEG_1);
	else if (key == KEY_X)
		fdf->pov->params.c += (5 * DEG_1);
	else if (key == KEY_C)
		fdf->pov->params.b -= (5 * DEG_1);
	else if (key == KEY_V)
		fdf->pov->params.b += (5 * DEG_1);
}

void	change_projections(int key, t_fdf *fdf)
{
	if (key == KEY_1)
		fdf->pov->projection = ISOMETRIC;
	else if (key == KEY_2)
		fdf->pov->projection = PERSPECTIVE;
	else if (key == KEY_3)
		fdf->pov->projection = TOP_DOWN;
}
