#include "../include/fdf.h"

void project(POV *pov, Vector *vector) {
  if (pov->projection == ISOMETRIC)
    isometric(vector, vector->p_a.x, vector->p_b.x);
  else if (pov->projection == PERSPECTIVE)
    perspective(vector);
  else if (pov->projection == TOP_DOWN)
    return;
}

void isometric(Vector *V, float a_x, float b_x) {
  V->p_a.x = (V->p_a.x - V->p_a.y) * cos(DEG_30);
  V->p_a.y = (a_x + V->p_a.y) * sin(DEG_30) - V->p_a.z;
  V->p_b.x = (V->p_b.x - V->p_b.y) * cos(DEG_30);
  V->p_b.y = (b_x + V->p_b.y) * sin(DEG_30) - V->p_b.z;
}

void perspective(Vector *V) {
  double z;

  rotate_x(V, V->p_a.y, V->p_b.y, 3 * -DEG_45);
  z = V->p_a.z + V->z;
  V->p_a.x = V->p_a.x / z;
  V->p_a.y = -(V->p_a.y / z);
  z = V->p_b.z + V->z;
  V->p_b.x = V->p_b.x / z;
  V->p_b.y = -(V->p_b.y / z);
  scale(V, V->z);
}
