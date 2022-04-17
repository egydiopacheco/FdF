/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_color(t_color *color, int z_value, int maximum_depth)
{
	float	gradient_factor;
	int		gradient_color;

	gradient_factor = (float)z_value / maximum_depth;
	gradient_color = (float)get_gradient_encoded(color, gradient_factor);
	return (gradient_color);
}

int	normalize(int value)
{
	if (value > 255)
		value = 255;
	else if (value < -255)
		value = 0;
	return (value);
}

int	get_gradient_encoded(t_color *color, float gradient_factor)
{
	int	r;
	int	g;
	int	b;
	int	encoded;

	r = normalize(color->dr * gradient_factor);
	r = r << 16;
	g = normalize(color->dg * gradient_factor);
	g = g << 8;
	b = normalize(color->db * gradient_factor);
	encoded = color->gradient.begin.encoded + (r + g + b);
	return (encoded);
}

void	colorfy_point(t_fdf *fdf, t_point *P)
{
	t_color	*color;
	int		z_value;
	int		maximum_depth;

	maximum_depth = ft_absolute_value(fdf->landscape->maximum_depth);
	z_value = ft_absolute_value(P->z);
	color = NULL;
	if (fdf->pov->color_pallet == false)
	{
		if (P->color == -1)
			P->color = VECTOR;
	}
	else if (P->z >= 0)
	{
		color = initialize_color_scheme(PASTEL_L_BROWN, PASTEL_D_BROWN);
		P->color = get_color(color, z_value, maximum_depth);
	}
	else
	{
		color = initialize_color_scheme(PASTEL_BROWN, PASTEL_D_GREEN);
		P->color = get_color(color, z_value, maximum_depth);
	}
	free(color);
}
