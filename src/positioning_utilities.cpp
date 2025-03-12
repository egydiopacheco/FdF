#include "../include/fdf.h"

void centralize(Landscape &landscape) {
  int half_width = landscape.horizontal_boundaries / 2;
  int half_height = landscape.vertical_boundaries / 2;

  for (int y = 0; y < landscape.vertical_boundaries; ++y) {
    for (int x = 0; x < landscape.horizontal_boundaries; ++x) {
      landscape.cartesian_plane[x][y].x -= half_height;
      landscape.cartesian_plane[x][y].y -= half_height;
    }
  }
}

float fit_screen(const Landscape *landscape) {
  float scale_factor = std::min(WINDOW_WIDTH / landscape->horizontal_boundaries,
                                WINDOW_HEIGHT / landscape->vertical_boundaries);

  return scale_factor < 3.85f ? 1.25f : scale_factor / 3.75f;
}
