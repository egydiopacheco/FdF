#include "../include/fdf.h"

void refresh(FDF *fdf) {
  fdf->pov->params.scaling_factor = fit_screen(fdf->landscape);
  fdf->pov->params.depth_scale = 1;
  fdf->pov->pos.x = WINDOW_WIDTH / 1.75;
  fdf->pov->pos.y = WINDOW_HEIGHT / 1.5;
  fdf->pov->params.a = 0;
  fdf->pov->params.b = 0;
  fdf->pov->params.c = 0;
}

void clear_image(Image *image, int image_size) {
  Point p;

  ft_bzero(image->address, image_size);
  p.y = 0;
  while (p.y < WINDOW_HEIGHT) {
    p.x = 0;
    while (p.x < WINDOW_WIDTH) {
      allocate_pixel_to_image(image, p, BACKGROUND);
      p.x++;
    }
    p.y++;
  }
}
