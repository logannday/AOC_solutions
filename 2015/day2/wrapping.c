#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int smallest_side_area(int l, int w, int h) {
  if (l <= h && w <= h) {
    return l * w;
  } else if (l <= w && h <= w) {
    return l * h;
  } else if (w <= l && h <= l) {
    return w * h;
  }
  printf("somethings wrong");
  return 0;
}

int ribbon_length(int l, int w, int h) {
  if (l <= h && w <= h) {
    return 2 * l + 2 * w;
  } else if (l <= w && h <= w) {
    return 2 * l + 2 * h;
  } else if (w <= l && h <= l) {
    return 2 * w + 2 * h;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  char line[20];
  // printf("%d %d %d", length, width, height);
  int total = 0;
  int ribbon = 0;
  while (fgets(line, 20, fp)) {
    char *line_string = strdup(line);
    int l = atoi(strsep(&line_string, "x"));
    int w = atoi(strsep(&line_string, "x"));
    int h = atoi(strsep(&line_string, "x"));
    total += (2 * l * w) + (2 * w * h) + (2 * l * h);
    total += smallest_side_area(l, w, h);
    ribbon += ribbon_length(l, w, h);
    ribbon += l * w * h;
  }

  printf("total wrapping: %d\n", total);
  printf("total ribbon: %d\n", ribbon);
  return 0;
}
