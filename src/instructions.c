/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*get_projection_name(t_fdf *fdf);
static void	show_movements(void *mlx, void *win, int pos_x);
static void	show_projections(void *mlx, void *win, int pos_x);
static void	show_other_actions(void *mlx, void *win, int pos_x);

void	show_instructions(t_fdf *fdf)
{
	int		pos_x;
	char	*projection;
	void	*mlx;
	void	*win;

	pos_x = 35;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, pos_x, 70, TEXT, projection);
	show_movements(mlx, win, pos_x);
	show_projections(mlx, win, pos_x);
	show_other_actions(mlx, win, pos_x);
}

static void	show_movements(void *mlx, void *win, int pos_x)
{
	mlx_string_put(mlx, win, pos_x, 105, TEXT, "Movement keys");
	mlx_string_put(mlx, win, pos_x, 115, TEXT,
		"-----------------------------");
	mlx_string_put(mlx, win, pos_x, 135, TEXT, "Zoom    : [UP]/[DOWN]");
	mlx_string_put(mlx, win, pos_x, 155, TEXT, "Move    : [W] [A] [S] [D]");
	mlx_string_put(mlx, win, pos_x, 175, TEXT, "Rotate X: [Z]/[X]");
	mlx_string_put(mlx, win, pos_x, 195, TEXT, "Rotate Y: [Q]/[E]");
	mlx_string_put(mlx, win, pos_x, 215, TEXT, "Rotate Z: [C]/[V]");
	mlx_string_put(mlx, win, pos_x, 235, TEXT, "Scale Z : [LEFT]/[RIGHT]");
}

static void	show_projections(void *mlx, void *win, int pos_x)
{
	mlx_string_put(mlx, win, pos_x, 255, TEXT, "Projections");
	mlx_string_put(mlx, win, pos_x, 265, TEXT,
		"-----------------------------");
	mlx_string_put(mlx, win, pos_x, 285, TEXT, "Isometric [1]");
	mlx_string_put(mlx, win, pos_x, 305, TEXT, "Perspective [2]'");
	mlx_string_put(mlx, win, pos_x, 325, TEXT, "Top down [3]");
}

static void	show_other_actions(void *mlx, void *win, int pos_x)
{
	mlx_string_put(mlx, win, pos_x, 350, TEXT, "Other actions");
	mlx_string_put(mlx, win, pos_x, 360, TEXT,
		"-----------------------------");
	mlx_string_put(mlx, win, pos_x, 380, TEXT, "Colorfy: [4]");
	mlx_string_put(mlx, win, pos_x, 400, TEXT, "Refresh [SPACE]");
	mlx_string_put(mlx, win, pos_x, 420, TEXT, "Exit [ESC]");
}

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->pov->projection == ISOMETRIC)
		projection = "ACTUAL PROJECTION: [Isometric]";
	else if (fdf->pov->projection == PERSPECTIVE)
		projection = "ACTUAL PROJECTION: [Perspective]";
	else if (fdf->pov->projection == TOP_DOWN)
		projection = "ACTUAL PROJECTION: [Top down]";
	return (projection);
}
