#include "../include/fdf.h"

Landscape *parse_landscape(char *filename) {
  Landscape *landscape;
  int fd;

  fd = open(filename, O_RDONLY, 0);
  if (fd < 0)
    raise_error(FILE_DESCRIPTOR_ERROR);
  close(fd);
  landscape = initialize_landscape();
  if (!landscape)
    return (NULL);
  landscape->horizontal_boundaries = get_width(filename);
  landscape->vertical_boundaries = get_height(filename);
  landscape->cartesian_plane = build_cartesian_plane(
      landscape->horizontal_boundaries, landscape->vertical_boundaries);
  if (!landscape->cartesian_plane) {
    free(landscape);
    return (NULL);
  }
  parse_points(filename, landscape);
  centralize(landscape);
  return (landscape);
}
