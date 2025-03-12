#include "../include/fdf.h"

Landscape *initialize_landscape(void) {
  Landscape *landscape;

  landscape = malloc(sizeof(Landscape));
  if (!landscape)
    return (NULL);
  fill_landscape_params(&landscape);
  return (landscape);
}

void fill_landscape_params(Landscape **landscape) {
  (*landscape)->cartesian_plane = NULL;
  (*landscape)->horizontal_boundaries = 0;
  (*landscape)->vertical_boundaries = 0;
  (*landscape)->maximum_depth = 0;
  (*landscape)->minimum_depth = 0;
}
