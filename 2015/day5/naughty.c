#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool three_vows(char *string) {
  int counter = 0;
  for (int i = 0; i < strlen(string); i++) {
    char c = string[i];
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U') {
      counter++;
    }
  }
  if (counter >= 3) {
    return true;
  }
  return false;
}

bool two_chars(char *string) {
  for (int i = 1; i < strlen(string); i++) {
    if (string[i] == string[i - 1]) {
      return true;
    }
  }
  return false;
}

bool no_bad_str(char *string) {
  if (strstr(string, "ab") || strstr(string, "cd") || strstr(string, "pq") ||
      strstr(string, "xy")) {
    return false;
  }
  return true;
}

bool is_nice(char *string) {
  if (three_vows(string) && two_chars(string) && no_bad_str(string)) {
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

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("null fp");
    exit(2);
  }
  printf("%d", count_nice(fp));
  return 0;
}
