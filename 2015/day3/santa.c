#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Coordinate_t;

typedef struct {
  Coordinate_t **visited;
  int index;
} Map_t;

#define MAP_SIZE 10000
void map_init(Map_t *map);
bool map_contains(Map_t *map, int x, int y);
bool map_add(Map_t *map, int x, int y);
int deliver_presents(Map_t *map, FILE *fp);
int robo_delivery(Map_t *map2, FILE *fp);

int main(int argc, char *argv[]) {
  Map_t map;
  map_init(&map);
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("null fp");
    exit(2);
  }
  int houses = robo_delivery(&map, fp);
  printf("num houses: %d\n", houses);
  return 0;
}
int robo_delivery(Map_t *map, FILE *fp) {
  int c;
  int index = 0;
  int x = 0;
  int y = 0;
  int rx = 0;
  int ry = 0;
  map_add(map, 0, 0);
  int num_houses = 1;
  while ((c = getc(fp)) != EOF) {
    if (c == '^') {
      (index) ? y++ : ry++;
    } else if (c == '>') {
      (index) ? x++ : rx++;
    } else if (c == '<') {
      (index) ? x-- : rx--;
    } else if (c == 'v') {
      (index) ? y-- : ry--;
    }
    if (!map_contains(map, x, y)) {
      num_houses++;
      map_add(map, x, y);
    }
    if (!map_contains(map, rx, ry)) {
      num_houses++;
      map_add(map, rx, ry);
    }
    if (index == 1) {
      index = 0;
    } else {
      index = 1;
    }
  }
  return num_houses;
}

int deliver_presents(Map_t *map, FILE *fp) {
  int c;
  int x = 0;
  int y = 0;
  map_add(map, 0, 0);
  int num_houses = 1;
  while ((c = getc(fp)) != EOF) {
    if (c == '^') {
      y++;
    } else if (c == '>') {
      x++;
    } else if (c == '<') {
      x--;
    } else if (c == 'v') {
      y--;
    }
    if (!map_contains(map, x, y)) {
      num_houses++;
      map_add(map, x, y);
    }
  }
  return num_houses;
}

void map_init(Map_t *map) {
  map->visited = (Coordinate_t **)calloc(MAP_SIZE, sizeof(Coordinate_t *));
  map->index = 0;
}

bool map_contains(Map_t *map, int x, int y) {
  bool contains = false;
  for (int i = 0; i < map->index; i++) {
    int map_x = map->visited[i]->x;
    int map_y = map->visited[i]->y;
    if (x == map_x && y == map_y) {
      contains = true;
    }
  }
  return contains;
}

bool map_add(Map_t *map, int x, int y) {
  if (map->index >= MAP_SIZE) {
    printf("out of bounds add\n");
    return false;
  }
  Coordinate_t *new_coord = (Coordinate_t *)malloc(sizeof(Coordinate_t));
  new_coord->x = x;
  new_coord->y = y;
  int index = map->index;
  map->visited[index] = new_coord;
  map->index++;
  return true;
}
