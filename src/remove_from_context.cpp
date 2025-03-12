#include "../include/fdf.h"

void destroy_everything(FDF *fdf, int exit_code) {
  destroy_cartesian_plane(fdf);
  destroy_image(fdf);
  destroy_pointers(fdf);
  free(fdf);
  raise_error(exit_code);
}

void destroy_image(FDF *fdf) {
  mlx_destroy_image(fdf->mlx_ptr, fdf->image->img_ptr);
  free(fdf->image);
  free(fdf->pov);
}

void destroy_landscape(FDF *fdf, int exit_code) {
  destroy_cartesian_plane(fdf);
  free(fdf->landscape);
  mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
  mlx_destroy_display(fdf->mlx_ptr);
  free(fdf);
  raise_error(exit_code);
}

void destroy_pointers(FDF *fdf) {
  mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
  mlx_destroy_display(fdf->mlx_ptr);
  free(fdf->mlx_ptr);
}

void destroy_cartesian_plane(FDF *fdf) {
  int i;

  i = 0;
  while (i < fdf->landscape->horizontal_boundaries) {
    free(fdf->landscape->cartesian_plane[i]);
    i++;
  }
  free(fdf->landscape->cartesian_plane);
  free(fdf->landscape);
}
