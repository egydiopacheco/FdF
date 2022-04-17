/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	initialize_fdf(t_fdf **fdf, char *filename)
{
	build_landscape(fdf, filename);
	(*fdf)->mlx_ptr = mlx_init();
	(*fdf)->win_ptr = mlx_new_window((*fdf)->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, TITLE);
	build_image(fdf);
	build_pov(fdf);
}
