/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	char	*filename;

	filename = argv[1];
	ensure_correct_input(argc, filename);
	start_driver(filename);
	return (0);
}

void	start_driver(char *filename)
{
	t_fdf	*fdf;

	build_fdf(&fdf);
	initialize_fdf(&fdf, filename);
	rasterize(fdf);
	mlx_hook(fdf->win_ptr, 17, 1L << 0, quit, fdf);
	mlx_key_hook(fdf->win_ptr, &hotkeys_hooks, fdf);
	mlx_expose_hook(fdf->win_ptr, &expose_handle, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int	expose_handle(t_fdf *fdf)
{
	rasterize(fdf);
	return (0);
}

int	quit(t_fdf *fdf)
{
	destroy_everything(fdf, 0);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}
