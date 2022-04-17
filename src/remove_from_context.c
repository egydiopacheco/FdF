/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_context.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	close_cartesian_plane(t_point **cartesian_plane, int width);

void	close_all(t_fdf *fdf, int exit_code)
{
	close_cartesian_plane(fdf->landscape->cartesian_plane,
		fdf->landscape->horizontal_boundaries);
	free(fdf->landscape);
	mlx_destroy_image(fdf->mlx_ptr, fdf->image->img_ptr);
	free(fdf->image);
	free(fdf->pov);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	raise_error(exit_code);
}

void	close_landscape(t_fdf *fdf, int exit_code)
{
	close_cartesian_plane(fdf->landscape->cartesian_plane,
		fdf->landscape->horizontal_boundaries);
	free(fdf->landscape);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf);
	raise_error(exit_code);
}

static void	close_cartesian_plane(t_point **cartesian_plane, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(cartesian_plane[i]);
		i++;
	}
	free(cartesian_plane);
}
