#include "../include/fdf.h"

Image *initialize_image(FDF *fdf) {
  Image *image;

  image = malloc(sizeof(Image));
  if (!image)
    return (NULL);
  fill_image_params(&image, fdf->mlx_ptr);
  return (image);
}

void fill_image_params(Image **image, void *mlx) {
  (*image)->img_ptr = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
  (*image)->address =
      mlx_get_data_addr((*image)->img_ptr, &(*image)->pixel_bits,
                        &(*image)->vector_size, &(*image)->endian);
  (*image)->vector = NULL;
  (*image)->menu = 0;
}
