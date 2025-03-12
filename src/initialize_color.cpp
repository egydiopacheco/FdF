#include "../include/fdf.h"

Color *initialize_color(Point p_a, Point p_b) {
  Color *color;

  color = malloc(sizeof(Color));
  if (!color)
    return (NULL);
  color->gradient.begin.encoded = p_a.color;
  color->gradient.begin.r = (RED & p_a.color) >> 16;
  color->gradient.begin.g = (GREEN & p_a.color) >> 8;
  color->gradient.begin.b = (BLUE & p_a.color);
  color->gradient.end.encoded = p_b.color;
  color->gradient.end.r = (RED & p_b.color) >> 16;
  color->gradient.end.g = (GREEN & p_b.color) >> 8;
  color->gradient.end.b = (BLUE & p_b.color);
  color->dr = (color->gradient.end.r - color->gradient.begin.r);
  color->dg = (color->gradient.end.r - color->gradient.begin.g);
  color->db = (color->gradient.end.b - color->gradient.begin.b);
  return (color);
}

Color *initialize_color_scheme(int min_color, int max_color) {
  Color *color;

  color = malloc(sizeof(Color));
  if (!color)
    return (NULL);
  color->gradient.begin.encoded = min_color;
  color->gradient.begin.r = (RED & min_color) >> 16;
  color->gradient.begin.g = (GREEN & min_color) >> 8;
  color->gradient.begin.b = (BLUE & min_color);
  color->gradient.end.encoded = max_color;
  color->gradient.end.r = (RED & max_color) >> 16;
  color->gradient.end.g = (GREEN & max_color) >> 8;
  color->gradient.end.b = (BLUE & max_color);
  color->dr = (color->gradient.end.r - color->gradient.begin.r);
  color->dg = (color->gradient.end.g - color->gradient.begin.g);
  color->db = (color->gradient.end.b - color->gradient.begin.b);
  return (color);
}
