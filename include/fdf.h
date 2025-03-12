#ifndef FDF_H
#define FDF_H

#include "aliases.h"
#include "colors.h"
#include "errors.h"
#include "structs.h"
#include <algorithm>
#include <fcntl.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

// builder.c
void build_fdf(FDF **fdf);
void build_landscape(FDF **fdf, char *filename);
void build_image(FDF **fdf);
void build_pov(FDF **fdf);

// cartesian_plane.c
Point **build_cartesian_plane(int width, int depth);

// checkings.c
void ensure_correct_input(int argc, char *filename);
void ensure_correct_extension(char *filename);

// color_utilities.c
int geColor(Color *color, int z_value, int maximum_depth);
int normalize(int value);
int get_gradient_encoded(Color *color, float gradient_factor);
void colorfy_point(FDF *fdf, Point *P);

// draw_line.c
void draw_line(FDF *fdf, Point p_a, Point p_b);

// draw_utilies.c
void allocate_pixel_to_image(Image *image, Point P, int color);
int calculate_amount_steps(float *dx, float *dy, Point p_a, Point p_b);
int is_out_of_bounds(Point P);

// driver.c
void start_driver(char *filename);
int expose_handle(FDF *fdf);
int quit(FDF *fdf);

// error_handler.c
void raise_error(int exit_code);
void error_extension(int error_code);

// hotkeys.c
int hotkeys_hooks(int key, FDF *fdf);
void moving_actions(int key, FDF *fdf);
void scaling_actions(int key, FDF *fdf);
void rotation_actions(int key, FDF *fdf);
void change_projections(int key, FDF *fdf);

// initialize_fdf.c
void initialize_fdf(FDF **fdf, char *filename);

// initialize_color.c
Color *initialize_color(Point p_a, Point p_b);
Color *initialize_color_scheme(int min_color, int max_color);

// initialize_image.c
Image *initialize_image(FDF *fdf);
void fill_image_params(Image **image, void *mlx);

// initialize_landscape.c
Landscape *initialize_landscape(void);
void fill_landscape_params(Landscape **landscape);

// initialize_pov.c
POV *initialize_pov(Landscape *landscape);
void fill_pov_params(POV **pov, Landscape *landscape);

// initialize_vector.c
Vector *initialize_vector(Point p_a, Point p_b, Landscape *landscape);

// instructions.c
void show_instructions(FDF *fdf);

// landscape_dimensions.c
int get_width(char *filename);
int get_height(char *filename);

// parser.c
Landscape *parse_landscape(char *filename);

// parser_utilities.c
void parse_points(char *filename, Landscape *landscape);
void single_point_mapping(int pos_x, int pos_y, Point **cartesian_plane);
void parse_poinColor(Landscape *landscape, int x, int y, char *vl);
void update_depth_values(int x, int y, Landscape *landscape);

// positioning_utilities.c  --> In C++
void centralize(Landscape *landscape);
float fit_screen(const Landscape *landscape);

// projection.c
void project(POV *pov, Vector *V);
void isometric(Vector *V, float a_x, float b_x);
void perspective(Vector *V);

// rasterize.c
void rasterize(FDF *fdf);
void check_and_plot(FDF *fdf, Point p, Point **coordinates);
void rasterize_vector(FDF *fdf, Point p_a, Point end);

// redo.c
void refresh(FDF *fdf);
void clear_image(Image *image, int image_size);

// remove_from_context.c
void destroy_everything(FDF *fdf, int exit_code);
void destroy_landscape(FDF *fdf, int exit_code);
void destroy_cartesian_plane(FDF *fdf);
void destroy_image(FDF *fdf);
void destroy_pointers(FDF *fdf);

// rotate.c
void rotate(POV *pov, Vector *vector);
void rotate_x(Vector *V, float a_y, float b_y, double theta);
void rotate_y(Vector *V, float a_x, float b_x, double theta);
void rotate_z(Vector *V, float a_x, float b_x, double theta);

// scale.c
void scale(Vector *vector, int scale_factor);

// transform.c
void transform(POV *pov, Vector *vector);

// translate.c
void translate(Vector *vector, int displacement_x, int displacement_y);

#endif
