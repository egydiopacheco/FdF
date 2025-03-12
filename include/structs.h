#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
struct Point {
  float x, y, z;
  int color;
};

struct Landscape {
  std::vector<std::vector<Point>> cartesian_plane;
  int horizontal_boundaries;
  int vertical_boundaries;
  int maximum_depth;
  int minimum_depth;

  Landscape(int width, int height)
      : horizontal_boundaries(width), vertical_boundaries(height),
        cartesian_plane(width, std::vector<Point>(height)) {}
};

struct Vector {
  Point p_a;
  Point p_b;
  float z;
};

struct Hexagon {
  Point p1;
  Point p2;
  Point p3;
  Point p4;
  Point p5;
  Point p6;
};

struct RGB {
  int r;
  int g;
  int b;
  int encoded;
};

struct Gradient {
  RGB begin;
  RGB end;
};

struct Color {
  Gradient gradient;
  int dr;
  int dg;
  int db;
};

struct Image {
  void *img_ptr;
  int pixel_bits;
  int vector_size;
  int endian;
  char *address;
  int menu;
  Vector *vector;
};

struct Params {
  float depth_scale;
  float scaling_factor;
  double a;
  double b;
  double c;
};

struct POV {
  int projection;
  int color_pallet;
  Params params;
  Point pos;
};

struct FDF {
  Landscape *landscape;
  void *mlx_ptr;
  void *win_ptr;
  Image *image;
  POV *pov;
};

#endif
