#include "../include/fdf.h"

int get_width(char *filename) {
  int fd;
  int width;
  char *line;

  fd = open(filename, O_RDONLY, 0);
  line = get_next_line(fd);
  if (!line)
    return (0);
  width = (int)ft_split_count(line, ' ');
  free(line);
  while (true) {
    line = get_next_line(fd);
    if (line == NULL)
      break;
    free(line);
  }
  close(fd);
  return (width);
}

int get_height(char *filename) {
  int fd;
  int depth;
  char *line;

  fd = open(filename, O_RDONLY, 0);
  depth = 0;
  while (true) {
    line = get_next_line(fd);
    if (line == NULL)
      break;
    depth++;
    free(line);
  }
  close(fd);
  return (depth);
}
