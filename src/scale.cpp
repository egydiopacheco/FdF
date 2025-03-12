#include "../include/fdf.h"

void scale(Vector *vector, int scale_factor) {
  vector->p_a.x *= scale_factor;
  vector->p_a.y *= scale_factor;
  vector->p_b.x *= scale_factor;
  vector->p_b.y *= scale_factor;
}
