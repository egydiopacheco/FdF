#include "../include/fdf.h"

void initialize_fdf(FDF **fdf, char *filename) {
  build_landscape(fdf, filename);
  (*fdf)->mlx_ptr = mlx_init();
  (*fdf)->win_ptr =
      mlx_new_window((*fdf)->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
  build_image(fdf);
  build_pov(fdf);
}
