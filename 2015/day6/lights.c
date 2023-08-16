#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void turn_on(int lights[][SIZE], int x1, int x2, int y1, int y2);
void turn_off(int lights[][SIZE], int x1, int x2, int y1, int y2);
void toggle(int lights[][SIZE], int x1, int x2, int y1, int y2);
int count(int lights[][SIZE]);
void light_show(int lights[][SIZE], FILE *fp);
void parse_toggle(int lights[][SIZE], char *line);
void print(int lights[][SIZE]);

int main(int argc, char *argv[]) {
  int lights[SIZE][SIZE] = {0};
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    exit(2);
  }
  light_show(lights, fp);
  printf("count: %d\n", count(lights));
  return 0;
}

void light_show(int lights[][SIZE], FILE *fp) {
  char line[40];
  char *args[5];
  char **ap;
  while (fgets(line, 40, fp)) {
    char *linecpy = strdup(line);
    for (ap = args; (*ap = strsep(&linecpy, " ")) != NULL;) {
      if (**ap != '\0') {
        if (++ap >= &args[5]) {
          break;
        }
      }
    }
    // printf("%s %s %s %s %s\n", args[0], args[1], args[2], args[3], args[4]);

    if (strcmp(args[0], "toggle") == 0) {
      int x1 = atoi(strtok(args[1], ","));
      int y1 = atoi(strtok(NULL, ","));
      int x2 = atoi(strtok(args[3], ","));
      int y2 = atoi(strtok(NULL, ","));
      toggle(lights, x1, x2, y1, y2);

    } else if (strcmp(args[1], "on") == 0) {
      int x1 = atoi(strtok(args[2], ","));
      int y1 = atoi(strtok(NULL, ","));
      int x2 = atoi(strtok(args[4], ","));
      int y2 = atoi(strtok(NULL, ","));
      turn_on(lights, x1, x2, y1, y2);

    } else if (strcmp(args[1], "off") == 0) {
      int x1 = atoi(strtok(args[2], ","));
      int y1 = atoi(strtok(NULL, ","));
      int x2 = atoi(strtok(args[4], ","));
      int y2 = atoi(strtok(NULL, ","));
      turn_off(lights, x1, x2, y1, y2);
    }
  }
}

void turn_on(int lights[][SIZE], int x1, int x2, int y1, int y2) {
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      lights[i][j]++;
    }
  }
}

void turn_off(int lights[][SIZE], int x1, int x2, int y1, int y2) {
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      if(lights[i][j] > 0) {
        lights[i][j]--;
      }
    }
  }
}

void toggle(int lights[][SIZE], int x1, int x2, int y1, int y2) {
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      lights[i][j] += 2;
    }
  }
}

int count(int lights[][SIZE]) {
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        counter += lights[i][j];
    }
  }
  return counter;
}

void print(int lights[][SIZE]) {
  printf("\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d|", lights[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
