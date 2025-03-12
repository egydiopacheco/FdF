#include "../include/fdf.h"

POV *initialize_pov(Landscape *landscape) {
  POV *pov;

  pov = malloc(sizeof(POV));
  if (!pov)
    return (NULL);
  fill_pov_params(&pov, landscape);
  return (pov);
}

void fill_pov_params(POV **pov, Landscape *landscape) {
  (*pov)->projection = ISOMETRIC;
  (*pov)->color_pallet = false;
  (*pov)->params.scaling_factor = fit_screen(landscape);
  (*pov)->params.depth_scale = 1;
  (*pov)->pos.x = WINDOW_WIDTH / 1.75;
  (*pov)->pos.y = WINDOW_HEIGHT / 1.5;
  (*pov)->params.a = 0;
  (*pov)->params.b = 0;
  (*pov)->params.c = 0;
}
