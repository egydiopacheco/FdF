#include "../include/fdf.h"

void translate(Vector *vector, int displacement_x, int displacement_y) {
  vector->p_a.x += displacement_x;
  vector->p_a.y += displacement_y;
  vector->p_b.x += displacement_x;
  vector->p_b.y += displacement_y;
}
