/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_image	*initialize_image(t_fdf *fdf)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	fill_image_params(&image, fdf->mlx_ptr);
	return (image);
}

void	fill_image_params(t_image **image, void *mlx)
{
	(*image)->img_ptr = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	(*image)->address = mlx_get_data_addr((*image)->img_ptr,
			&(*image)->pixel_bits,
			&(*image)->vector_size,
			&(*image)->endian);
	(*image)->vector = NULL;
	(*image)->menu = 0;
}
