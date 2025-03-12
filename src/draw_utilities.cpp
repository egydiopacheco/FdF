#include "../include/fdf.h"

int is_out_of_bounds(Point P) {
  if (P.x > 0 && P.y > 0 && P.x < WINDOW_WIDTH && P.y < WINDOW_HEIGHT)
    return (IN_BOUNDS);
  else
    return (OUT_OF_BOUNDS);
}

int calculate_amount_steps(float *dx, float *dy, Point p_a, Point p_b) {
  int steps;

  *dx = p_b.x - p_a.x;
  *dy = p_b.y - p_a.y;
  steps =
      (int)ft_max_value_between(ft_absolute_value(*dx), ft_absolute_value(*dy));
  *dx /= steps;
  *dy /= steps;
  return (steps);
}

void allocate_pixel_to_image(Image *image, Point P, int color) {
  int pixel;

  pixel = ((int)P.y * image->vector_size) + ((int)P.x * 4);
  if (image->endian == 1) {
    image->address[pixel + 0] = (color >> 24);
    image->address[pixel + 1] = (color >> 16) & 0xff;
    image->address[pixel + 2] = (color >> 8) & 0xff;
    image->address[pixel + 3] = (color) & 0xff;
  } else if (image->endian == 0) {
    image->address[pixel + 0] = (color) & 0xff;
    image->address[pixel + 1] = (color >> 8) & 0xff;
    image->address[pixel + 2] = (color >> 16) & 0xff;
    image->address[pixel + 3] = (color >> 24);
  }
}
