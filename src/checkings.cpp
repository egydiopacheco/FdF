#include "../include/fdf.h"

void ensure_correct_input(int argc, char *filename) {
  if (argc != 2)
    raise_error(INPUT_ERROR);
  ensure_correct_extension(filename);
}

void ensure_correct_extension(char *filename) {
  char *slice;
  char *extension;

  slice = ft_strrchr(filename, '.');
  if (slice == NULL || slice == filename)
    slice = "";
  extension = slice + 1;
  if (ft_strcmp(extension, "fdf"))
    raise_error(EXTENSION_MISMATCH);
}
