#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool contains_dub(char *string);
bool one_between(char *string);
bool is_nice(char *string);
int count_nice(FILE *fp);

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("null fp");
    exit(2);
  }
  printf("count nice: %d", count_nice(fp));
  return 0;
}

bool contains_dub(char *string) {
  int length = strlen(string);

  for (int i = 1; i < length; i++) {
    int char1 = string[i - 1];
    int char2 = string[i];
    for (int j = 1; j < length; j++) {
      if (j == i - 1 || j == i || j == i + 1) {
        continue;
      }
      if (char1 == string[j - 1] && char2 == string[j]) {
        return true;
      }
    }
  }
  return false;
}

bool one_between(char *string) {
  for (int i = 2; i < strlen(string); i++) {
    if (string[i] == string[i - 2]) {
      return true;
    }
  }

  return false;
}

bool is_nice(char *string) {
  if(one_between(string) && contains_dub(string)) {
    return true;
  }
  return false;
}

int count_nice(FILE *fp) {
  char line[30];
  int num_nice = 0;
  while (fgets(line, 30, fp)) {
    if (is_nice(line)) {
      num_nice++;
    }
  }
  return num_nice;
}
