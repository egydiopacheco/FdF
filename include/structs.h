/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct s_landscape
{
	t_point		**cartesian_plane;
	int			horizontal_boundaries;
	int			vertical_boundaries;
	int			maximum_depth;
	int			minimum_depth;
}				t_landscape;

typedef struct s_vector
{
	t_point		p_a;
	t_point		p_b;
	float		z;
}				t_vector;

typedef struct s_hexagon
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_point		p5;
	t_point		p6;
}				t_hexagon;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
	int			encoded;
}				t_rgb;

typedef struct s_gradient
{
	t_rgb		begin;
	t_rgb		end;
}				t_gradient;

typedef struct s_color
{
	t_gradient	gradient;
	int			dr;
	int			dg;
	int			db;
}				t_color;

typedef struct s_image
{
	void		*img_ptr;
	int			pixel_bits;
	int			vector_size;
	int			endian;
	char		*address;
	int			menu;
	t_vector	*vector;
}				t_image;

typedef struct s_params
{
	float		depth_scale;
	float		scaling_factor;
	double		a;
	double		b;
	double		c;

}				t_params;

typedef struct s_pov
{
	int			projection;
	int			color_pallet;
	t_params	params;
	t_point		pos;
}				t_pov;

typedef struct s_fdf
{
	t_landscape	*landscape;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	t_pov		*pov;
}				t_fdf;

#endif
