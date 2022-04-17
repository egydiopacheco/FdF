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

void	destroy_everything(t_fdf *fdf, int exit_code)
{
	destroy_cartesian_plane(fdf);
	destroy_image(fdf);
	destroy_pointers(fdf);
	free(fdf);
	raise_error(exit_code);
}

void	destroy_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->image->img_ptr);
	free(fdf->image);
	free(fdf->pov);
}

void	destroy_landscape(t_fdf *fdf, int exit_code)
{
	destroy_cartesian_plane(fdf);
	free(fdf->landscape);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf);
	raise_error(exit_code);
}

void	destroy_pointers(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
}

void	destroy_cartesian_plane(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->landscape->horizontal_boundaries)
	{
		free(fdf->landscape->cartesian_plane[i]);
		i++;
	}
	free(fdf->landscape->cartesian_plane);
	free(fdf->landscape);
}
