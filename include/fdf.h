/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "aliases.h"
# include "colors.h"
# include "errors.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

// builder.c
void		build_fdf(t_fdf **fdf);
void		build_landscape(t_fdf **fdf, char *filename);
void		build_image(t_fdf **fdf);
void		build_pov(t_fdf **fdf);

// cartesian_plane.c
t_point		**build_cartesian_plane(int width, int depth);

// checkings.c
void		ensure_correct_input(int argc, char *filename);
void		ensure_correct_extension(char *filename);

// color_utilities.c
int			get_color(t_color *color, int z_value, int maximum_depth);
int			normalize(int value);
int			get_gradient_encoded(t_color *color, float gradient_factor);
void		colorfy_point(t_fdf *fdf, t_point *P);

// draw_line.c
void		draw_line(t_fdf *fdf, t_point p_a, t_point p_b);

// draw_utilies.c
void		allocate_pixel_to_image(t_image *image, t_point P, int color);
int			calculate_amount_steps(float *dx, float *dy, t_point p_a,
				t_point p_b);
int			is_out_of_bounds(t_point P);

// driver.c
void		start_driver(char *filename);
int			expose_handle(t_fdf *fdf);
int			quit(t_fdf *fdf);

// error_handler.c
void		raise_error(int exit_code);
void		error_extension(int error_code);

// hotkeys.c
int			hotkeys_hooks(int key, t_fdf *fdf);
void		moving_actions(int key, t_fdf *fdf);
void		scaling_actions(int key, t_fdf *fdf);
void		rotation_actions(int key, t_fdf *fdf);
void		change_projections(int key, t_fdf *fdf);

// initialize_fdf.c
void		initialize_fdf(t_fdf **fdf, char *filename);

//initialize_color.c
t_color		*initialize_color(t_point p_a, t_point p_b);
t_color		*initialize_color_scheme(int min_color, int max_color);

// initialize_image.c
t_image		*initialize_image(t_fdf *fdf);
void		fill_image_params(t_image **image, void *mlx);

// initialize_landscape.c
t_landscape	*initialize_landscape(void);
void		fill_landscape_params(t_landscape **landscape);

// initialize_pov.c
t_pov		*initialize_pov(t_landscape *landscape);
void		fill_pov_params(t_pov **pov, t_landscape *landscape);

// initialize_vector.c
t_vector	*initialize_vector(t_point p_a, t_point p_b,
				t_landscape *landscape);

// instructions.c
void		show_instructions(t_fdf *fdf);

// landscape_dimensions.c
int			get_width(char *filename);
int			get_depth(char *filename);

// parser.c
t_landscape	*parse_landscape(char *filename);

// parser_utilities.c
void		parse_points(char *filename, t_landscape *landscape);
void		single_point_mapping(int pos_x, int pos_y,
				t_point **cartesian_plane);
void		parse_point_color(t_landscape *landscape, int x, int y, char *vl);
void		update_depth_values(int x, int y, t_landscape *landscape);

// positioning_utilities.c
void		centralize(t_landscape *landscape);
float		fit_screen(t_landscape *landscape);

// projection.c
void		project(t_pov *pov, t_vector *V);

// rasterize.c
void		rasterize(t_fdf *fdf);
void		check_and_plot(t_fdf *fdf, t_point p, t_point **coordinates);
void		rasterize_vector(t_fdf *fdf, t_point p_a, t_point end);

// redo.c
void		refresh(t_fdf *fdf);
void		clear_image(t_image *image, int image_size);

// remove_from_context.c
void		close_all(t_fdf *fdf, int exit_code);
void		close_landscape(t_fdf *fdf, int exit_code);

// rotate.c
void		rotate(t_pov *pov, t_vector *vector);
void		rotate_x(t_vector *V, float a_y, float b_y, double angle);
void		rotate_y(t_vector *V, float a_x, float b_x, double angle);
void		rotate_z(t_vector *V, float a_x, float b_x, double angle);

// scale.c
void		scale(t_vector *vector, int scale_factor);

// transform.c
void		transform(t_pov *pov, t_vector *vector);

// translate.c
void		translate(t_vector *vector, int displacement_x, int displacement_y);

#endif
