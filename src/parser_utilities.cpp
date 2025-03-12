#include "../include/fdf.h"

void parse_points(char *filename, Landscape *landscape) {
  int fd;
  char *line;
  char **vectorized_line;
  Point p;

  fd = open(filename, O_RDONLY, 0);
  p.y = 0;
  while (true) {
    p.x = 0;
    line = get_next_line(fd);
    if (line == NULL)
      break;
    vectorized_line = ft_split(line, ' ');
    while (p.x < landscape->horizontal_boundaries) {
      parse_point_color(landscape, p.x, p.y, vectorized_line[(int)p.x]);
      free(vectorized_line[(int)p.x]);
      p.x++;
    }
    free(vectorized_line);
    free(line);
    p.y++;
  }
  close(fd);
}

void parse_point_color(Landscape *landscape, int x, int y, char *vl) {
  int i;
  char **color_code;

  single_point_mapping(x, y, landscape->cartesian_plane);
  i = 0;
  if (ft_strchr(vl, ',')) {
    color_code = ft_split(vl, ',');
    landscape->cartesian_plane[x][y].z = (float)ft_atoi(color_code[0]);
    landscape->cartesian_plane[x][y].color =
        ft_atoi_base(color_code[1], HEXA_BASE);
    while (color_code[i])
      free(color_code[i++]);
    free(color_code);
  } else {
    landscape->cartesian_plane[x][y].z = (float)ft_atoi(vl);
    landscape->cartesian_plane[x][y].color = -1;
  }
  update_depth_values(x, y, landscape);
}

void single_point_mapping(int pos_x, int pos_y, Point **cartesian_plane) {
  cartesian_plane[pos_x][pos_y].x = pos_x;
  cartesian_plane[pos_x][pos_y].y = pos_y;
}

void update_depth_values(int x, int y, Landscape *landscape) {
  if (landscape->cartesian_plane[x][y].z > landscape->maximum_depth)
    landscape->maximum_depth = landscape->cartesian_plane[x][y].z;
  if (landscape->cartesian_plane[x][y].z < landscape->minimum_depth)
    landscape->minimum_depth = landscape->cartesian_plane[x][y].z;
}
