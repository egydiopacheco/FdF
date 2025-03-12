#include "../include/fdf.h"

void build_fdf(FDF **fdf) {
  *fdf = (FDF *)malloc(sizeof(FDF));
  if (*fdf == NULL)
    raise_error(FDF_BUILD_ERROR);
}

void build_landscape(FDF **fdf, char *filename) {
  (*fdf)->landscape = parse_landscape(filename);
  if (!(*fdf)->landscape) {
    free(*fdf);
    raise_error(LANDSCAPE_BUILD_ERROR);
  }
}

void build_image(FDF **fdf) {
  (*fdf)->image = initialize_image(*fdf);
  if (!(*fdf)->image)
    destroy_landscape(*fdf, IMAGE_BUILD_ERROR);
}

void build_pov(FDF **fdf) {
  (*fdf)->pov = initialize_pov((*fdf)->landscape);
  if (!(*fdf)->pov)
    destroy_everything(*fdf, POV_BUILD_ERROR);
}
